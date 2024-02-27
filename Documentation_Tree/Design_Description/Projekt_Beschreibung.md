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
Eine Matrix besteht aus vier quadratischen LED's mit 8x8 LED's. Somit besteht ein Matrixverbund aus 8x32 LED's. Für die Realisierung von zwei Tetris Feldern haben wir vier dieser Verbünde mithilfe der Daisy-Chain Methode verbunden. Die LED's sind alle einheitlich in rot.

### Mikrocomputer

Für die Steuerung und der Logik der gesamten Systemarchitektur ist der Mikrocomputer zuständig. Hier haben wir auf ein klassisches Arduino-Kit mit einem Arduino MEGA zurückgegriffen.

### Controller
Ein absolutes Alleinstellungsmerkmal ist die Implementierung von SNES-Controllern. Mithilfe festgelegter Eingabetasten lassen sich die Blöcke bewegen drehen und das Spiel unterbrechen. Die gesamte Steuerung läuft über die Controller ab. Die Anschlüsse sind unterhalb der Matrix angebracht. Bei Fehlfunktionen oder Beschädigungen, lässt sich der Controller einfach austauschen. 

### LCD
Das LCD (Liquid Crystal Display) ist im Gehäuse über der Matrix angebracht. Es besitzt zwei Zeilen, die den Punktestand der einzelnen Spieler anzeigen.