# Coding Standards 
## General
Variable names shall be descriptiv in the given context and not use abbreviation except for common used ones (i.e. x, y, z or i in loops).

Magic numbers should be avoided if possible. 

For for-loops, if-statements and switch-case-statemants should always have a defined body with "{}" even when it could be written without.

Example:
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

## Type Usage
For integer types the cstdint library should be used 

## Comments
Comments which explaing a function an it's parameter shall always be written with doxygen
```
[missing example]
```
---

Comments should be placed where the function of code might not be so obvious.

Comments for indenpendet code snippets should be written with the "//" even if spanning over mutiple lines.

Example:
```
// This is a comment

// This is certainly
// a comment which is
// a bit longer
```

## Naming Conventions
### Filenames
Source and header files shall be named in lower case and in case of an compound word spaced accordingly with underscores.

Example:
```
tetris.c
tetris.h
music_manager.c
music_manager.h
```
---
###  Variables
Macros should always be named capitalized. If the name is an compound word it will be spaced with an underscore accordingly.

Example:
```
#define SIZE 10
#define MAX_LENGTH 20
```
---
The name of a variable in general should be written in camelCase (with potential prefixes).

Example:
```
uint8_t countDown = 0;
float time = 0f;
bool isActivated = false;
```

The asterisk (*) for pointers is next to the type additionally pointers will be named with and "p_" prefix. 

Example:
```
int8_t* p_dataInput;
```
---
Arrays should be if possible always named in plural as well as marked with a "a_" prefix.

Example:
```
uint8_t a_numbers[SIZE];
```
---

Classes, Struct and Enums shall be named in PascalCase.
Private variables should we named with an "m_" prefix while public varaibles remain named as normal ones.

Example:
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

### Functions
Function names will be declared with with camelCase and an additional "fn_" infront. The funcition body shall start on a new line.

Example:
```
void fn_drawScreen(int16_t a, char b)
{
    // function body
}
```