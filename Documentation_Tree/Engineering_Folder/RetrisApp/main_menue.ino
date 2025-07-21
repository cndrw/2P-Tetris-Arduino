#include "renderer.h"
#include "audio.h"
#include "main_menue.h"
#include "retris_os.h"
#include "input.h"

void MainMenue::PushButton()
{
  Audio::PlayAudio(AUDIO_BUTTON_PRESS);

  // small hack to open the settings menu
  // possibility was originally not intended
  if (openSettings)
  {
    retris.ChangeProcess(SYS_PROCESS_MENUE, SETTINGS_MENUE);
  }
  else
  {
    retris.ChangeProcess(SYS_PROCESS_GAME, m_selectedButton + 1);
  }
}

void MainMenue::ButtonSelect()
{
  Audio::PlayAudio(AUDIO_BUTTON_SWITCH);
  m_selectedButton = m_selectedButton == 1 ? 0 : 1;
  // even it is not a block this function can be used to include any vector array
  Renderer::IncludeBlock(arrow, arrowPosition[m_selectedButton], 3);
  Renderer::RemoveBlock(arrow, arrowPosition[!m_selectedButton], 3);

  openSettings = Input::GetButtonDown(CONTROLLER_1, BUTTON_START);
}

