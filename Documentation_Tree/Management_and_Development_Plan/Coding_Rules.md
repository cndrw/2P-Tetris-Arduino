# Coding Standards 
## Allgemein
Variablennamen sollen den gegebenen Kontext beschreiben und keine Abkürzungen verwenden, außer für häufig verwendete (z. B. x, y, z oder i in Schleifen).

Magische Zahlen sollten vermieden werden, wenn möglich.

Für for-Schleifen, if-Anweisungen und switch-case-Anweisungen sollte immer ein definierter Körper mit "{}" vorhanden sein, auch wenn es nicht notwendig ist.

Beispiel:
```
if (input == Input.right)
{
    // do something
}

for (int i = 0; i < MAX_LENGTH; i++)
{
    // more code
}

switch (gameState)
{
    case 0:
        break;
    case 1:
        break;
}
```

## Typenverwendung
Für Ganzzahltypen (integer) sollte die cstdint-Bibliothek verwendet werden. 

## Kommentare
Kommentare, die eine Funktion und ihre Parameter erklären, sollten immer mit Doxygen geschrieben werden.
```
[missing example]
```
---

Kommentare sollten dort platziert werden, wo die Funktion des Codes möglicherweise nicht so offensichtlich ist.

Kommentare für unabhängige Code-Schnipsel sollten mit "//" geschrieben werden, auch wenn sie über mehrere Zeilen gehen.

Beispiel:
```
// This is a comment

// This is certainly
// a comment which is
// a bit longer
```

## Namenskonventionen
### Dateinamen
Quell- und Headerdateien sollen in Kleinbuchstaben benannt werden und bei zusammengesetzten Wörtern entsprechend mit Unterstrichen versehen sein.

Beispiel:
```
tetris.c
tetris.h
music_manager.c
music_manager.h
```
---
###  Variablen
Makros sollten immer großgeschrieben werden. Wenn der Name aus mehreren Wörtern besteht, wird er entsprechend mit einem Unterstrich versehen.

Beispiel:
```
#define SIZE 10
#define MAX_LENGTH 20
```
---
Der Name einer Variablen im Allgemeinen sollte in camelCase geschrieben werden (mit potenziellen Präfixen).

Beispiel:
```
uint8_t countDown = 0;
float time = 0f;
bool isActivated = false;
```

## Definitionen
Verwenden von Makros anstelle von Enums. Enums belegen Speicher, während Makros dies nicht tun. Um die richtige Verwendung sicherzustellen, wenn sie über mehrere Dateien hinweg verwendet werden, sollen kohärente Makros mit einem gemeinsamen Titel beginnen.

Beispiel:
```
#define GAME_STATE_PLAY 0
#define GAME_STATE_PAUSE 1

#define MENUE_MAIN 0
#define MENUE_PAUSE 1
```

Das Asterisk (*) für Zeiger steht neben dem Typ, zusätzlich werden Zeiger mit einem Präfix "p_" benannt.

Beispiel:
```
int8_t* p_dataInput;
```
---
Arrays sollten, wenn möglich, immer im Plural benannt werden und mit einem "a_"-Präfix markiert sein.

Beispiel:
```
uint8_t a_numbers[SIZE];
```
---

Klassen, Strukturen und Enums sollen in PascalCase benannt werden. Private Variablen sollten mit einem "m_"-Präfix benannt werden, während öffentliche Variablen wie normale benannt bleiben.

Beispiel:
```
class GameManager
{
    public:
        int32_t timePassed = 0f;

    private:
        int8_t m_gameState = 0;
        int8_t* mp_block;
};

struct Vector
{
    int16_t x;
    int16_t y;
};

public enum Input
{
    int8_t right;
    int8_t left;
    int8_t up;
    int8_t down;
}
```

### Funktionen
Funktionsnamen werden in camelCase und mit einem zusätzlichen "fn_" vorangestellt deklariert. Der Funktionskörper sollte auf einer neuen Zeile beginnen.

Beispiel:
```
void fn_drawScreen(int16_t a, char b)
{
    // function body
}
```
