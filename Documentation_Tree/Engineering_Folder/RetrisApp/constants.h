#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "vector.h"
#include <LiquidCrystal_I2C.h>

#define SIMULATION 0
#define DEBUG 0

#define CLK 52
#define CS 53
#define DIN 51

#define SIZE 16
#define ROWS 8

#define BLOCK_LENGTH 4

#define GAME_WIDTH_WB 12
#define GAME_HEIGHT_WB 22
#define GAME_WIDTH 10
#define GAME_HEIGHT 20

#define LBLOCK {{0,0}, {-1,0}, {1,0}, {-1,1}}
#define JBLOCK {{0,0}, {1, 0}, {-1 ,0}, {1, 1}}
#define TBLOCK {{0,0}, {1,0}, {-1,0}, {0,1}}
#define SBLOCK {{0,0}, {1,0}, {0, 1}, {-1, 1}}
#define ZBLOCK {{0,0}, {0,1}, {-1, 0}, {1, 1}}
#define OBLOCK {{0,0}, {0,1}, {1,1}, {1,0}}
#define IBLOCK {{0,0}, {-1, 0}, {1, 0}, {-2, 0}}

#define LBLOCK_PREVIEW {{0, 0}, {0, 1}, {0, -1}, {1, 1}}
#define JBLOCK_PREVIEW {{0,0}, {0,-1}, {0,1}, {-1,1}}
#define SBLOCK_PREVIEW_ {{0,0}, {-1,0}, {-1,-1}, {0, 1}}
#define ZBLOCK_PREVIEW {{0,0}, {0,1}, {1,0}, {1,-1}}

#define L 0
#define J 1
#define T 2
#define S 3
#define Z 4
#define O 5
#define I 6

#define MOVE_RIGHT 1
#define MOVE_LEFT 2
#define MOVE_BELOW 3

#define GAME_OPT_1P 1
#define GAME_OPT_2P 2
#define GAME_OPT_LAST 3

#define MAIN_MENUE 0
#define DEATH_MENUE 1
#define PAUSE_MENUE 2
#define SETTINGS_MENUE 3

#if SIMULATION
#define BUTTON_NONE 0
#define BUTTON_RIGTH 1
#define BUTTON_LEFT 2
#define BUTTON_A 3
#define BUTTON_DOWN 4
#define BUTTON_START 5
#endif

#define BUTTON_HEIGHT 5


#define CLEAR_ANIMATION_LENGTH 5
#define DEATH_ANIMATION_LENGTH 5

int32_t screen[ROWS * 4] = {0};

namespace HW
{
  LiquidCrystal_I2C lcd(0x27, 16, 2);
}


Vector blockShape[7][4] = {
  LBLOCK,
  JBLOCK,
  TBLOCK,
  SBLOCK,
  ZBLOCK,
  OBLOCK,
  IBLOCK
};

Vector previewBlockShape[7][4] = {
  LBLOCK_PREVIEW,
  JBLOCK_PREVIEW,
  TBLOCK,
  SBLOCK_PREVIEW_,
  ZBLOCK_PREVIEW,
  OBLOCK,
  IBLOCK
};

#endif
