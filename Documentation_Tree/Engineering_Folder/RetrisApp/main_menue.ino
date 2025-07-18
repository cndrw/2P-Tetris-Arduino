#include "renderer.h"
#include "audio.h"
#include "main_menue.h"
#include "retris_os.h"

void MainMenue::PushButton()
{
  // conviently m_selectedButton alternates between 1 and 0 
  // and the SYS_OPT for 1P and 2P alternates between 1 and 2
  Audio::PlayAudio(AUDIO_BUTTON_PRESS);
  retris.ChangeProcess(SYS_PROCESS_GAME, m_selectedButton + 1);
}

void MainMenue::ButtonSelect()
{
  Audio::PlayAudio(AUDIO_BUTTON_SWITCH);
  m_selectedButton = m_selectedButton == 1 ? 0 : 1;
  // even it is not a block this function can be used to include any vector array
  Renderer::IncludeBlock(arrow, arrowPosition[m_selectedButton], 3);
  Renderer::RemoveBlock(arrow, arrowPosition[!m_selectedButton], 3);
}
