#ifndef INPUT_H
#define INPUT_H

#define CONTROLLER_1 0
#define CONTROLLER_2 1

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

namespace Input {

struct Controller
{
  bool currInput[BUTTON_AMOUNT] = {1};
  bool lastInput[BUTTON_AMOUNT] = {1};
};

static constexpr uint8_t dataLatch[] = { 3, 7 };
static constexpr uint8_t dataClock[] = { 2, 6 };
static constexpr uint8_t dataSerial[] = { 4, 12 };
// static bool buttons[2][12] = {1}; 
static Controller controllers[2]; // max 2 controller with 12 buttons
static uint8_t controllerCount = 2;


/**
 * @brief sets how many controller are actively checked
 * @param number number of controller
*/
void SetControllerCount(const uint8_t number)
{
  controllerCount = number;
}
    
/**
 * @brief setups the controller pins
*/
void SetupPins()
{
  for (int i = 0; i < controllerCount; i++)
  {
    // Set DATA_CLOCK normally HIGH
    pinMode(dataClock[i], OUTPUT);
    digitalWrite(dataClock[i], HIGH);

    pinMode(dataLatch[i], OUTPUT);
    digitalWrite(dataLatch[i], LOW);

    pinMode(dataSerial[i], OUTPUT);
    digitalWrite(dataSerial[i], HIGH);
    pinMode(dataSerial[i], INPUT);  
  }
}

/**
 * @brief reads the current state of the controller(s)
*/
void ReadControllerInputs()
{
  // Latch for 12us
  for (uint8_t j = 0; j < controllerCount; j++)
  {

    digitalWrite(dataLatch[j], HIGH);
    delayMicroseconds(12);
    digitalWrite(dataLatch[j], LOW);
    delayMicroseconds(6);

    // Retrieve button presses from shift register by pulling the clock high for 6us
    for(uint8_t i = 0; i < 16; i++)
    {
      digitalWrite(dataClock[j], LOW);
      delayMicroseconds(6);
      if(i <= 16)
      {
        // current inputs will be written in last input befor getting updated
        memcpy(controllers[j].lastInput, controllers[j].currInput, sizeof(bool) * BUTTON_AMOUNT);
        controllers[j].currInput[i] = digitalRead(dataSerial[j]);
      }
      digitalWrite(dataClock[j], HIGH);
      delayMicroseconds(6);
    }   
  }
}

/**
 * @brief checks if the desired button is currently pressed
 * @param controller which controller shall be checked
 * @param button which button shall be checked
*/
bool GetButton(const uint8_t controller, const uint8_t button)
{
  // if the button is pressed it is represented with a 0 in the buttons array
  return controllers[controller].currInput[button] == BUTTON_PRESSED;
}


/**
 * @brief checks if the desired button got pressed (only the transition)
 * @param controller which controller shall be checked
 * @param button which button shall be checked
*/
bool GetButtonDown(const uint8_t controller, const uint8_t button)
{
  // checked if there is a falling signal => button got pressed
  return (controllers[controller].currInput[button] == BUTTON_PRESSED) &&
         (controllers[controller].lastInput[button] == BUTTON_NOT_PRESSED);
}

}; // Input

#endif