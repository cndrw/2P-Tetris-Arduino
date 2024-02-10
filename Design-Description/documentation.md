# Retris - technische Dokumentation
Diese Dokument zeigt den strukturellen Aufbau des Projektes "Retris" und die Gedanken hinter den Implementierungen. Eine genauere Dokumentation des Quellcodes findet sie [hier](https://www.youtube.com/watch?v=dQw4w9WgXcQ).

# Inhalt
- [Hardware](#hardware)
    - [Display](#display)
- [Rendering](#rendering)
    - [interne Representation des Displays](#interne-representation)
    - [Übertragung des internen Zustands](#übertraung-des-internen-screen)
- [OS-Struktur](#os---struktur)
    - [Processes](#processes)
    - [MenueHandler](#menuehandler)
    - [GameManager](#gamemanager)
- [Spiellogik](#spiellogik) 
    - [Input Management](#input-management)
    - [Kollisions Erkennung](#collision-detection)
    - [Full-Line Erkennung](#full-line-detection)


## Hardware
### Display
Das Display hat eine gesamt größe von 32x32 LEDs, welche aus 16 verschiedenen 8x8 LED-Modulen zusammengesetzt ist. Diese einzelnen Module sind per Dasy-Chain verbunden.

## Rendering
### interne Representation des Displays
Die Matrix die zur visualiserung genutzt wird verfügt über 32x32 LEDs, dass heißt die interne Representation muss es ermöglichen den Zustand aller 1024 LEDs abzuspeichern und zu verändern.

Aufgrund dessen, dass unsere gewählte Matrix einfarbig ist, kann jede LED einfacherweise mit nur einem Bit dargestellt werden (an oder aus). Dementsprechen wird das gesamte Display mittels einem simplen Array der Länge 32, welches 32-Bit Integer speichert dargestellt. Dabei representiert der Index des Arrays die Zeile und die Position des Bits innerhalb des Integers die Spalte (MSB -> Spalte 0). Der Koordinaten Ursprung wurde als die linke obere Ecke definiert, des Weiteren steigt der y-Wert nach unten an.

```
                x
 _ _|_ _ _ _ _ _ >
    |
    |
 y  u
```

```
Zeile |    Spalte
----------------------------
      |    | 0 | 1 | 2 | 3 | . . .
0     | 0b | x | x | x | x |
1     | 0b | x | x | x | x |
2     | 0b | x | x | x | x |
.
.
.
```
#### Beispiele
```
// anschalten der linken oberen LED (0, 0)
screen[0] |= 0x8000'0000 // oder screen[0] |= (int32_t)1 << 31

// ausschalten der LEDs (5, 10) und (6, 10)
screen[10] |= 0x0C00'0000 // oder screen[10] |= (int32_t)2 << (31 - 6)
```

### Übertraung des internen Screen
Die [interne Darstellung des Displays](#interne-representation-des-displays) kann leider nicht in dieser Form an die Matrizen übertagen werden. Die SPI-Übertragung besteht in diesem Fall aus vier Schritten:
1. Chip-Select auf LOW
2. senden um welche Zeile es handelt (`SPI.transfer(row)`)
3. senden welche LEDs in dieser Reihe welchen Zustand haben (`SPI.transfer(reihe)`)
4. Chip-Select auf HIGH

Zu beachten dabei ist, dass sich diese Schritte auf ein einzelnes [LED-Modul](#display) des Displays bezieht. Dementsprechend kann man nur zwischen der Zeilen 1-8 auswählen und die Reihe wird Bit-Weise durch eine 8-Bit Zahl dargestellt. Das hat zur folge, dass man bei einer Übertragung nur eine Zeile eines Modules auf einmal ändern kann. Um also alle LEDs des Display einmal neu zu zeichnen, müssen 128 (8 Zeilen * 16 Module) Übertragungen stattfinden. Eine letzte besonderheit der Übertragung kommt durch das Daisy-Chaining. Um die Daten an das richtige Modul durchzureichen, darf Chip-Select nicht auf HIGH gesetzt wird.  

Um alle LEDs neu zu zeichnen, müssen 128 Übertragungen stattfinden. Dies wird durch eine Doppelte For-Schleife erreicht, wobei die äußere über die Anzahl der Zeilen eines Moduls iteriert und die inner über die Anzahl der Module.

```
for (int i = 0; i < ROWS; i++) {    // ROWS = 8
    digitalWrite(CS, LOW);
    for (int j = 0; i < SIZE; j++){     // SIZE = 16
        // ...
    }
    digitalWrite(CS, HIGH);
}
```


Dass heißt, die erste Datenübertragung wird 16 mal durchgeschoben und landet letztenendlich bei dem letzten Modul. Danach ist Chip-Select auf HIGH und die nächste Zeile jedem Moduls kann übertragen werden. Durch den Anordnung der der Matrizen sieht die Übertragungsreihenfolge dann so aus:
```
--------------------
| 1  | 2  | 3  | 4  |
--------------------
| 5  | 6  | 7  | 8  |
--------------------
| 9  | 10 | 11 | 12 |
--------------------
| 13 | 14 | 15 | 16 |
--------------------
```
Der letzte Schritte des Renderns, ist es die 32-Bit Integer Zahl, welche eine ganze Reihe representiert, so zu zerlegen, dass zum richtigen Zeitpunkt die jeweiligen 8-Bit übertragen werden.
Zuerst muss deshalb die richtige Reihe ausgewählt werden. Die erste Übertragung sendet die erste Zeile in jeweils 8-Bit teilen, danach muss man im internen screen um 8 Zeilen springen und sendet wieder die gesamte Reihe. Als Folge würde der y-Wert des internen screens wie folgt aussehen: 0,0,0,0,8,8,8,8,16,16,16,16,24,24,24,24. Das Verhalten lässt sich mittels einer Integer-Division erreichen.
```
// innerhalb der beiden For-Schleifen
{
    // (j / 4) * 8 ergibt das Verhalten wie oben beschrieben
    // + i spezifiziert um welche Reihe vom 8x8 LED-Modul es sich handel
    row = screen[i + (j / 4) * 8]; // Y-Wert des screens
}
```
Aufgrund der Übertragungsreihenfolge, muss aus dem Integer der eine Zeile representiert die vier MSB zuerst versendet werden und die vier LSB zuletzt. Dass heißt der Zahl muss zuerst um 6 Byte nach rechts verschoben werden, danach um 4, dann um 2 und die vier LSB müssen nicht extra verschoben werden. Nachdem der ganze Integer zerteilt und übertrage wurde, muss dies von neu beginngen. Diese Folgen verhalten lässt sich mittels dem Modulo Operator verwirklichen.
```
// innerhalb der beiden For-Schleifen
{
    // nur die 4 LSB werden gespeichert, der Rest wird abgeschitten
    uint8_t dataToSend = currentRow >> ((6 - ((j % 4) * 2)) * 4)
}
```
Der Teil `(j % 4) * 2` ermöglicht die Folge: 0,2,4,6,0,2,... Mit der `6 - ` davor erreichen wir die richtige Reihenfolge der Folge und die Multiplikation mit vier bewirkt die Byte verschiebung. Alles zusammen sieht dann wie folgt aus:
```
// innerhalb der beiden For-Schleifen
{
    uint8_t data = screen[i + (j / 4) * 8] >> ((6 - ((j % 4) * 2)) * 4);
    
    SPI.transfer(i + 1); // addressierung des moduls ist um eins verschoben
    SPI.transfer(data);
}
```
Dies Übertragung wird von der `DrawScreen` funktion ausgefürht, diese zeichnet nach jedem OS-Tick den momentan Zustand des internen `screen`.



## OS-Struktur
### Processes
### MenueHandler
### GameManager
---
## SpielLogik
### Input Management
### Kollisions Erkennung
### Full-Line Erkennung

