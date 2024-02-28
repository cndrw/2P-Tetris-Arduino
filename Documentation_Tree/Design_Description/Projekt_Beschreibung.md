<!-- Table of contents -->
# Inhalt

1. [Kurzbeschreibung](#kurzbeschreibung)
2. [Aufbau](#aufbau)
    - [Gehäuse](#gehäuse)
    - [LED-Matrix](#led-matrix)
    - [Mikrocomputer](#mikrocomputer)
    - [Controller](#controller)
    - [LCD](#lcd)


# Kurzbeschreibung

**Retris** ist eine Neuauflage des legendären Puzzlespiels Tetris, das darauf abzielt, das Retro-Gaming zu erneuern und gleichzeitig den Bedürfnissen moderner Spieler gerecht zu werden. Das Spiel wird mit einem Controller gesteuert, um das Gaming Spielerlebnis zu bewahren, während es gleichzeitig durch innovative Funktionen wie einen Zwei-Spieler-Modus und dem originalen Soundtrack ergänzt wird.

Das kompakte und tragbare Design macht Retris zu einem idealen Begleiter für unterwegs.

Retris baut auf dem Erbe des Originalspiels Tetris auf und strebt danach, die Welt des Retro-Gamings auf eine neue Ebene zu heben.

# Aufbau

Grundsätzlich ist es kompakt und einfach gehalten. Es besteht aus einem Gehäuse, indem sich der Mikrocontroller und die Verdrahtungen befinden. So werden die Verdrahtungen geschützt und es gibt ein  besseres Design. Außerdem beinhaltet das Gehäuse die LED-Matrix, die Controller-Anschlüsse, sowie das LCD (Liquid Crystal Display). An das Gehäuse werden dann zwei SNES-Controller, sowie ein USB-C Netzkabel angebracht.

### Gehäuse
Das Gehäuse ist ein 3D gefertigtes Konstrukt. Eine technische Zeichnung können sie dem ``Engineering_Folder`` entnehmen. Es besteht aus drei einzelnen Teilen, die anschließend verschraubt worden sind, sodass sich Kabelbrüche o.ä. Fehler leicht beheben lassen. Auf dem einen Teil sind die vier LED-Matrizen festgelötet, sodass diese immer in einem Verbund sind. Die anderen beiden Teile stellen dann das eigentliche Gehäuse dar. Im Gehäusedeckel wurden einige Aussparungen gemacht, sodass man dort die entsprechenden Komponenten und Anschlüsse vom Gehäuseinneren sehen kann.

### LED-Matrix
<!--Eine Matrix besteht aus vier quadratischen LED's mit 8x8 LED's. Somit besteht ein Matrixverbund aus 8x32 LED's. 
Für die Realisierung von zwei Tetris Feldern haben wir vier dieser Verbünde mithilfe der Daisy-Chain Methode verbunden. 
Die LED's sind alle einheitlich in rot.-->

Das Spielfeld wird auf einer 32x32 Matrix, bestehend aus roten LEDs, dargestellt. Diese Matrix setzt sich zusammen aus vier einzelnen Modulen der Größe 8x32.
Ein Modul setzt sich zusammen aus vier Matrix Einheiten mit einer Anordnung von 8x8 LEDs und wird durch einen MAX7219 Treiber angesteuert. 
Die Ansteuerung der Matrix erfolgt über die SPI-Schnittstelle (Pins: 51, 52, 53) des Mikrocontrollers. Die Datenverbindung erfolgt ab Pin 51 per Daisy-Chain-Verbindung, in Reihe, zu den weiteren Modulen. Hierbei wird jeweils eine Verbindung vom Dout (Data-out) Schnittstelle zum Din (Data-In) des folgenden Moduls hergestellt.
Zusätzlich erhalten die Module jeweils ein Clock Signal (CLK) und ein Slave-select (CS) Signal zur Ansteuerung. Beide Signale werden parallel gesendet.
Die Spannungsversorgung der Matrizen erfolgt durch den gemeinsamen Anschluss an die externe Spannungsquelle (5V).
Um beispielsweise die Helligkeit der LEDs zu steuern oder andere Anpassungen vorzunehmen, können im Code verschiedene Einstellungen vorändert werden.

### Mikrocontroller

Für die Steuerung und der Logik der gesamten Systemarchitektur ist der Mikrocomputer zuständig. 
Hier haben wir auf ein klassisches Arduino-Kit mit einem Arduino MEGA zurückgegriffen. Dieses bietet bereits einige Bauteile und Leitungen die für unser Projekt von nötig sind.
Die Wahl des Arduino MEGA mit dem Kern ATmega2560 war eine reine Vorsichtsmaßnahme um zu vermeiden dass uns der Speicherplatz des Chips definitv ausreicht. Der Mikrocontroller bietet uns genügend digitale und analoge Pins, um die Ansteuerung der LED-Matrix, der beiden SNES-Controller, des Buzzers und des LCD zu realisieren.


### SNES-Controller
Ein absolutes Alleinstellungsmerkmal ist die Implementierung von SNES-Controllern. Mithilfe festgelegter Eingabetasten lassen sich die Blöcke bewegen drehen und das Spiel unterbrechen. Die gesamte Steuerung läuft über die Controller ab. Die Anschlüsse sind unterhalb der Matrix angebracht. Bei Fehlfunktionen oder Beschädigungen, lässt sich der Controller durch ``Plug & play`` austauschen.
Für die Abfrage der Eingabe werden fünf Verbindungen benötigt. Diese bestehen aus Versorgungspannung und Erdung (Vcc, GND) und drei weiteren Leitungen um die Daten abzurufen (Data Clock, Data Latch, Serial Data). 
Erdung und Spannungsversorgung werden ebenfalls über die Externe Spannungsquelle (5V) bereitgestellt. Die Datenleitungen können individuell an drei digitale Pins des Mikrocontroller angeschlossen werden, dabei benötigt jeder Controller seine eigens im Code zugeordneten Pins.
Die Datenübertragung basiert auf auf einem Simplex-SPI Protokoll, hierbei werden Daten nur in eine Richtung von einem Gerät zum anderen übertragen. Um ein Eingabesignal vom Controller zu erhalten muss das Protokoll des SNES-Systems reproduziert werden.
Hierbei wird mit einem High-Signal (5V) Puls auf dem Latch Pin die Abfrage gestartet. Daraufhin wird eine Clock-Signal erstellt das von High (5V) zu Low (0V) wechselt. Hierbei wird im Hintergrund, vom Mikrocontroller, mitgezählt welcher Clockpuls in Abhängigkeit der Zeit auftritt. 
Sollte ein Knopf auf dem Controller gedrückt sein, wird das Data-Signal Low gesetzt und der Mikrocontroller kann die Information auslesen. Der Zeitpunkt wann das Signal Low wird ist entscheidend für die korrekte Interpretation der Eingabe. Das Signal wird für einen bestimmten Knopf zu einem bestimmten Zeitpunkt Low und kann somit durch das Zählen der Clocksignale definiert werden.
<!--![Bild](../Engineering_Folder/images/Snes_signal.png)-->
<p><img src="../Engineering_Folder/images/Snes_signal.png" width="600"></p>

Quellen:
[Circuitcellar](https://circuitcellar.com/research-design-hub/projects/interfacing-with-video-game-controllers/)
[Bitluni](https://bitluni.net/gamepad)

### Spannungsversorgung
Zu Anfang des Projekts standen verschiedene Möglichkeiten zur Spannungsversorgung zur Auswahl. Diese hat sich mit Festlegung der einzelnen Komponenten auf eine einfache Lösung reduziert.
Wir entschieden uns nach abwägen der Möglichkeiten dafür eine externe Spannungsquelle zu nutzen und diese per USB Typ-C Anschluss abnehmbar zu gestalten. 
Den Strom liefert ein handeslsübliches USB-Netzteil in Form eines Ladegerätes bekannt von Smartphones. Dieses leifert eine Spannung von 5V und 3A Strom, damit steht uns eine Leistung von 15 Watt zu Verfügung.
Eine weitere Möglichkeit die noch im Raum steht und bei einer zukünftigen Version des Projektes genutzt werden kann, ist die Integration einer Powerbank mit entsprechender Leistung. Diese könnte leicht in das Gehäuse integriert werden.
Hierzu müssten nur einige Anpassungen vorgenommen werden, darunter zählt das Hinzufügen eines Ladeanschlusses und eines Schalters um die Stromzufuhr beliebig zu beeinflussen.

### I2C-LCD
Das LCD (Liquid Crystal Display) ist im Gehäuse über der Matrix angebracht. Es besitzt zwei Zeilen, die den Punktestand der einzelnen Spieler anzeigen.
Die Ansteuerung des LCD erfolgt über die I2C-Schnittstelle (Pins: 20 SDA, 21 SCL) des Mikrocontrollers. Die Spannungsversorgung des LCD erfolgt durch den gemeinsamen Anschluss an die externe Spannungsquelle (5V).
Das LCD war Teil des Arduino Kits und wurde somit nicht extra angeschafft. 

### Buzzer
Beim Buzzer handelt es sich um den Lautsprecher der Teil des Aurduino-Development Kits ist. Dieser wird im Gehäuse verbaut und gibt den bekannten Tetris Song wieder.
Die Ansteuerung des Buzzers erfolgt über einen digitalen PWM-Pin des Mikrocontrollers.

### Schaltplan
<!--![Schaltplan Retris](../Engineering_Folder/images/Curcuitry_vorläufig.png)-->
<p><img src="../Engineering_Folder/images/Curcuitry_vorläufig.png" width="600"></p>

Der Schaltplan zeigt die Verkabelung der einzelnen Komponenten. Die Farben wurden wie folgt gewählt:
- Rot: Spannungsversorgung (5V)
- Schwarz: Erdung (GND)
- Orange: Datenleitungen
- Lila: Clock-Signale
- Pink: Latch/CS/SS-Signale

Der Schaltplan wurd mit Hilfe von Wokwi erstellt, hierbei war es leider nicht möglich die Schnittstellen für die Controller realitätsnah darzustellen, daher wurde diese nur schematisch dargestellt.