#ifndef INPUT_H
#define INPUT_H

#define BUTTON_AMOUNT 12

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
 * @brief sets how many controller are actively checked
 * @param number number of controller
*/
void SetControllerCount(const uint8_t number);
/**
 * @brief setups the controller pins
*/
void SetupPins();
/**
 * @brief reads the current state of the controller(s)
*/
void ReadControllerInputs();
/**
 * @brief checks if the desired button is currently pressed
 * @param controller which controller shall be checked
 * @param button which button shall be checked
*/
bool GetButton(const uint8_t controller, const uint8_t button);
/**
 * @brief checks if the desired button got pressed (only the transition)
 * @param controller which controller shall be checked
 * @param button which button shall be checked
*/
bool GetButtonDown(const uint8_t controller, const uint8_t button);

}; // Input

#endif