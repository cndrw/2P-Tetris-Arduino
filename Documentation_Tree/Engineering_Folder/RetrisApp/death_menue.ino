#include "death_menue.h"
#include "audio.h"
#include "retris_os.h"
#include "renderer.h"

#define BUTTON_RETRY 0
#define BUTTON_MENUE 1
#define BUTTON_HEIGHT 5

void DeathMenue::PushButton()
{
  switch(m_selectedButton)
  {
    case BUTTON_RETRY:
      retris.ChangeProcess(SYS_PROCESS_GAME, GAME_OPT_LAST);
      break;

    case BUTTON_MENUE:
      Audio::PlayAudio(AUDIO_BUTTON_PRESS);
      retris.ChangeProcess(SYS_PROCESS_MENUE, MAIN_MENUE);
      break;
  }
}

void DeathMenue::RefreshMenue()
{
    // to alternate the button (make it blink)
    static uint8_t tick = 0;
    tick++;
    tick %= 2;

    if (tick == 1)
    {
    Renderer::IncludeRows(m_selectedButton == 0 ? button1 : button2, 
                            buttonPositions[m_selectedButton], BUTTON_HEIGHT);
    }
    else
    {
    uint8_t buttonPos = buttonPositions[m_selectedButton];
    Renderer::ClearRows(buttonPos, buttonPos + BUTTON_HEIGHT);
    }
}

void DeathMenue::ButtonSelect()
{
  if (Input::GetButtonDown(CONTROLLER_1, BUTTON_DOWN) ||
      Input::GetButtonDown(CONTROLLER_1, BUTTON_UP))
  {
    Audio::PlayAudio(AUDIO_BUTTON_SWITCH);
    Renderer::IncludeRows(button1, 18, 5); // 18 = pos of first button
    Renderer::IncludeRows(button2, 25, 5); // 25 = pos of second button
    m_selectedButton = m_selectedButton == 1 ? 0 : 1;
    RefreshMenue();
  }
}