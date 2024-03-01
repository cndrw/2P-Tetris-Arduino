#include "input.h"

#define BUTTON_PRESSED 0
#define BUTTON_NOT_PRESSED 1

#define BUTTON_AMOUNT 12
#define BUTTON_B 0
#define BUTTON_Y 1
#define BUTTON_SELECT 2
#define BUTTON_START 3
#define BUTTON_UP 4
#define BUTTON_DOWN 5
#define BUTTON_LEFT 6
#define BUTTON_RIGHT 7
#define BUTTON_A 8
#define BUTTON_X 9
#define BUTTON_L 10
#define BUTTON_R 11

#define CONTROLLER_1 0
#define CONTROLLER_2 1

namespace Input {

void SetControllerCount(const uint8_t number)
{
  controllerCount = number;
}
    
void SetupPins()
{
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

    digitalWrite(controllser[i].dataLatch, HIGH);
    delayMicroseconds(12);
    digitalWrite(controllers[i].dataLatch, LOW);
    delayMicroseconds(6);

    // current inputs will be written in last input befor getting updated
    memcpy(controllers[j].lastInput, controllers[j].currInput, sizeof(bool) * BUTTON_AMOUNT);
    // Retrieve button presses from shift register by pulling the clock high for 6us
    for(uint8_t i = 0; i < 16; i++)
    {
      digitalWrite(controllers[i].dataClock, LOW);
      delayMicroseconds(6);
      if(i <= 16)
      {
        controllers[j].currInput[i] = digitalRead(controllers[i].dataSerial);
        
      }
      digitalWrite(controllers[i].dataClock, HIGH);
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
