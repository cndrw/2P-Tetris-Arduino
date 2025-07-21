#include "menue_handler.h"

#if !SIMULATION
#include "input.h"
#endif

void MenueHandler::AddMenue(Menue* p_menue)
{
  static uint8_t menueCount = 0;
  mp_menues[menueCount] = p_menue;
  menueCount++;
}

void MenueHandler::Init(uint8_t menue)
{
  mp_menues[menue]->Init();
  mp_menues[menue]->DrawMenue();
  m_currentMenue = menue;
}

void MenueHandler::Update()
{
#if !SIMULATION
  if (Input::GetButtonDown(CONTROLLER_1, BUTTON_A))
  {
    mp_menues[m_currentMenue]->PushButton();
  }

  if (Input::GetButtonDown(CONTROLLER_1, BUTTON_DOWN) ||
      Input::GetButtonDown(CONTROLLER_1, BUTTON_UP))
  {
    mp_menues[m_currentMenue]->ButtonSelect();
  }
#endif

  // to restrict the refresh speed of a menu
  // there is no need that the menues refreshes at such a high rate
  static uint8_t ticks = 0;
  ticks++;
  ticks %= 20;

  if (ticks == 0)
  {
    mp_menues[m_currentMenue]->RefreshMenue();
  }
}

#if SIMULATION
void MenueHandler::Input(uint8_t pressedButton, uint8_t)
{
  switch(pressedButton)
  {
    case BUTTON_A:
      mp_menues[m_currentMenue]->PushButton();
      break;

    case BUTTON_DOWN:
      mp_menues[m_currentMenue]->ButtonSelect();
      break;

    default:
      break;
  }
}
#endif

