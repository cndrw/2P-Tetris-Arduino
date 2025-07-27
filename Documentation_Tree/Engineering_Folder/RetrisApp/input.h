#ifndef INPUT_H
#define INPUT_H

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

struct Controller
{
  bool currInput[BUTTON_AMOUNT] = {1};
  bool lastInput[BUTTON_AMOUNT] = {1};
  uint8_t dataClock;
  uint8_t dataLatch;
  uint8_t dataSerial;
};

static Controller controllers[2]; // max 2 controller with 12 buttons
static uint8_t controllerCount = 2;

/**
 * @brief Sets how many controller are actively checked
 * @param number Number of controller
*/
void SetControllerCount(const uint8_t number);
/**
 * @brief Setups the controller pins
*/
void SetupPins();
/**
 * @brief Reads the current state of the controller(s)
*/
void ReadControllerInputs();
/**
 * @brief Checks if the desired button is currently pressed
 * @param controller Which controller shall be checked
 * @param button Which button shall be checked
*/
bool GetButton(const uint8_t controller, const uint8_t button);
/**
 * @brief Checks if the desired button got pressed (only the transition from unpressed to pressed)
 * @param controller Which controller shall be checked
 * @param button Which button shall be checked
*/
bool GetButtonDown(const uint8_t controller, const uint8_t button);

}; // Input

#endif