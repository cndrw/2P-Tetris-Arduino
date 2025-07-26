#include "renderer.h"
#include "audio.h"
#include "main_menue.h"
#include "retris_os.h"
#include "input.h"

void MainMenue::Init()
{
  HW::lcd.setCursor(0, 0);
  HW::lcd.print("Highscore:");
  HW::lcd.setCursor(0, 1);
  HW::lcd.print(config.highscore);
}

void MainMenue::PushButton()
{
  Audio::PlayAudio(AUDIO_BUTTON_PRESS);

  // small hack to open the settings menu
  // possibility was originally not intended
  HW::lcd.clear();
  retris.ChangeProcess(SYS_PROCESS_GAME, m_selectedButton + 1);
}

void MainMenue::ButtonSelect()
{

  if (Input::GetButtonDown(CONTROLLER_1, BUTTON_DOWN) ||
      Input::GetButtonDown(CONTROLLER_1, BUTTON_UP))
  {
    Audio::PlayAudio(AUDIO_BUTTON_SWITCH);
    m_selectedButton = m_selectedButton == 1 ? 0 : 1;
    // even it is not a block this function can be used to include any vector array
    Renderer::IncludeBlock(m_arrow, m_arrowPosition[m_selectedButton], 3);
    Renderer::RemoveBlock(m_arrow, m_arrowPosition[!m_selectedButton], 3);
  }

  if (Input::GetButtonDown(CONTROLLER_1, BUTTON_START))
  {
    Audio::PlayAudio(AUDIO_BUTTON_PRESS);
    retris.ChangeProcess(SYS_PROCESS_MENUE, SETTINGS_MENUE);
  }
}


