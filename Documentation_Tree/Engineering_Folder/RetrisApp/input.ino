#include "input.h"

namespace Input {

void SetControllerCount(const uint8_t number)
{
  controllerCount = number;
}
    
void SetupPins()
{
  controllers[0].dataSerial = 12;
  controllers[0].dataLatch = 7;
  controllers[0].dataClock = 6;
  controllers[1].dataSerial = 4;
  controllers[1].dataLatch = 3;
  controllers[1].dataClock = 2;
  // always set up for two controller
  for (int i = 0; i < 2; i++)
  {
    // not using the registers directly too keep it easy readable
    // Set DATA_CLOCK normally HIGH
    pinMode(controllers[i].dataClock, OUTPUT);
    digitalWrite(controllers[i].dataClock, HIGH);

    pinMode(controllers[i].dataLatch, OUTPUT);
    digitalWrite(controllers[i].dataLatch, LOW);

    pinMode(controllers[i].dataSerial, OUTPUT);
    digitalWrite(controllers[i].dataSerial, HIGH);
    pinMode(controllers[i].dataSerial, INPUT);  
  }
}

void ReadControllerInputs()
{
  // Latch for 12us
  for (uint8_t j = 0; j < controllerCount; j++)
  {

    digitalWrite(controllers[j].dataLatch, HIGH);
    delayMicroseconds(12);
    digitalWrite(controllers[j].dataLatch, LOW);
    delayMicroseconds(6);

    // current inputs will be written in last input befor getting updated
    memcpy(controllers[j].lastInput, controllers[j].currInput, sizeof(bool) * BUTTON_AMOUNT);

    // Retrieve button presses from shift register by pulling the clock high for 6us
    for(uint8_t i = 0; i < 16; i++)
    {
      digitalWrite(controllers[j].dataClock, LOW);
      delayMicroseconds(6);

      if (i <= 11)
      {
        controllers[j].currInput[i] = digitalRead(controllers[j].dataSerial);
      }
        
      digitalWrite(controllers[j].dataClock, HIGH);
      delayMicroseconds(6);
    }   
  }
}

bool GetButton(const uint8_t controller, const uint8_t button)
{
  // if the button is pressed it is represented with a 0 in the buttons array
  return controllers[controller].currInput[button] == BUTTON_PRESSED;
}

bool GetButtonDown(const uint8_t controller, const uint8_t button)
{
  // checked if there is a falling signal => button got pressed
  return (controllers[controller].currInput[button] == BUTTON_PRESSED) &&
         (controllers[controller].lastInput[button] == BUTTON_NOT_PRESSED);
}

}; // INPUT
