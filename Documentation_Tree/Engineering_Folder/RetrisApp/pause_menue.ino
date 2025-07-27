#include "pause_menue.h"
#include "audio.h"
#include "renderer.h"
#include "constants.h"
#include "retris_os.h"
#include "config.h"

#define BUTTON_RESUME 0
#define BUTTON_MENUE 1

void PauseMenue::RefreshMenue()
{
  static uint8_t tick = 0;
  tick++;
  tick %= 2;

  // draw (odd) and remove (even) the selected button 
  if (tick == 1)
  {
    Renderer::IncludeRows(m_selectedButton == 0 ? buttonResume : buttonMenue, 
                          buttonPositions[m_selectedButton], BUTTON_HEIGHT);
  }
  else
  {
    uint8_t buttonPos = buttonPositions[m_selectedButton];
    Renderer::ClearRows(buttonPos, buttonPos + BUTTON_HEIGHT);
  }
}

void PauseMenue::PushButton()
{
  switch(m_selectedButton)
  {
    case BUTTON_RESUME:
      if (config.musicEnabled)
      {
        Audio::PlayAudio(AUDIO_KOROBEINIKI, true, true);
      }
      retris.UnFreezeProcess();
      break;

    case BUTTON_MENUE:
      Audio::PlayAudio(AUDIO_BUTTON_PRESS);
      retris.ChangeProcess(SYS_PROCESS_MENUE, MAIN_MENUE);
      break;

    default:
      break;
  } 
}

void PauseMenue::ButtonSelect()
{
  if (Input::GetButtonDown(CONTROLLER_1, BUTTON_DOWN) ||
      Input::GetButtonDown(CONTROLLER_1, BUTTON_UP))
  {
    Audio::PlayAudio(AUDIO_BUTTON_SWITCH);

    Renderer::IncludeRows(buttonResume, buttonPositions[0], 5);
    Renderer::IncludeRows(buttonMenue, buttonPositions[1], 5);
    m_selectedButton = m_selectedButton == 1 ? 0 : 1; // there are only two buttons
    RefreshMenue();
  }
}
