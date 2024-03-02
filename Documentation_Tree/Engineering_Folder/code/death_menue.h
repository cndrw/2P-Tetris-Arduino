#ifndef DEATH_MENUE_H
#define DEATH_MENUE_H

#include "menue.h"

const int32_t DeathMenueSprite[32] = {
0b00000000000000000000000000000000,
0b00001111111111111111111111110000,
0b00010000000000000000000000001000,
0b00100001100011001000101111000100,
0b00010010000100101101101000001000,
0b00100010110111101010101110000100,
0b00010010010100101000101000001000,
0b00100001100100101000101111000100,
0b00010000000000000000000000001000,
0b00100001100100010111101110000100,
0b00010010010100010100001001001000,
0b00100010010010100111001110000100,
0b00010010010010100100001010001000,
0b00100001100001000111101001000100,
0b00010000000000000000000000001000,
0b00001111111111111111111111110000,
0b00000000000000000000000000000000,
0b00000000000000000000000000000000,
0b01110011110111001000001100100010,
0b01001010000100101000010010100010,
0b01110011100111001000011110011100,
0b01010010000100001000010010001000,
0b01001011110100001111010010001000,
0b00000000000000000000000000000000,
0b00000000000000000000000000000000,
0b00000010001011110100101001000000,
0b00000011011010000110101001000000,
0b00000010101011100101101001000000,
0b00000010001010000100101001000000,
0b00000010001011110100100110000000,
0b00000000000000000000000000000000,
0b00000000000000000000000000000000
};

/**
* @brief Implementation of the Menue interface
* @details If the player reaches the death menu (game over), he can choose to either
* play again the current mode or to go to the main menu 
*/
class DeathMenue : public Menue
{
  public:
    DeathMenue() : Menue(DeathMenueSprite) {}
    ~DeathMenue() {}

    void PushButton();
    void RefreshMenue();
    void ButtonSelect();

  private:

    const uint8_t buttonPositions[2] = { 18, 25 };
    const int32_t button1[5] = {
      0b01110011110111001000001100100010,
      0b01001010000100101000010010100010,
      0b01110011100111001000011110011100,
      0b01010010000100001000010010001000,
      0b01001011110100001111010010001000
    };

    const int32_t button2[5] = {
      0b00000010001011110100101001000000,
      0b00000011011010000110101001000000,
      0b00000010101011100101101001000000,
      0b00000010001010000100101001000000,
      0b00000010001011110100100110000000  
    };
};

#endif