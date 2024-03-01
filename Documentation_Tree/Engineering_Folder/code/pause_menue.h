#ifndef PAUSE_MENUE_H
#define PAUSE_MENUE_H

#include "menue.h"

const int32_t PauseMenueSprite[32] = {
0b00000000000000000000000000000000,
0b00111111111111111111111111111100,
0b01000000000000000000000000000010,
0b01001110001100110110011101110010,
0b01001001010010110110100001000010,
0b01001110011110110110011001100010,
0b01001000010010110110000101000010,
0b01001000010010110110111001110010,
0b01000000000000000000000000000010,
0b00111111111111111111111111111100,
0b00000000000000000000000000000000,
0b00000000000000000000000000000000,
0b00000000000000000000000000000000,
0b00000000000000000000000000000000,
0b01110011110011101001010001011110,
0b01001010000100001001011011010000,
0b01110011100011001001010101011100,
0b01010010000000101001010001010000,
0b01001011110111000110010001011110,
0b00000000000000000000000000000000,
0b00000000000000000000000000000000,
0b00000000000000000000000000000000,
0b00000000000000000000000000000000,
0b00000010001011110100100100100000,
0b00000011011010000110100100100000,
0b00000010101011100101100100100000,
0b00000010001010000100100100100000,
0b00000010001011110100100011000000,
0b00000000000000000000000000000000,
0b00000000000000000000000000000000,
0b00000000000000000000000000000000,
0b00000000000000000000000000000000
};

/**
* @brief Implementation of the Menue interface
* @details In the pause menu the player can choose to either resume the current game
* or to go to the main menu
*/
class PauseMenue : public Menue
{
  public:
    PauseMenue() : Menue(PauseMenueSprite) {}
    ~PauseMenue() {}
    void RefreshMenue();
    void PushButton();
    void ButtonSelect();

  private:
    const uint8_t buttonPositions[2] = { 14, 23 };
    const int32_t buttonResume[5] = {
      0b01110011110011101001010001011110,
      0b01001010000100001001011011010000,
      0b01110011100011001001010101011100,
      0b01010010000000101001010001010000,
      0b01001011110111000110010001011110
    };

    const int32_t buttonMenue[5] = {
      0b00000010001011110100100100100000,
      0b00000011011010000110100100100000,
      0b00000010101011100101100100100000,
      0b00000010001010000100100100100000,
      0b00000010001011110100100011000000    
    };
};

#endif