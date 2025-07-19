#include "settings_menue.h"
#include "audio.h"
#include "renderer.h"


void SettingsMenue::PushButton()
{
  Audio::PlayAudio(AUDIO_BUTTON_PRESS);
}

void SettingsMenue::ButtonSelect()
{
  Audio::PlayAudio(AUDIO_BUTTON_SWITCH);

  m_selectedButton = m_selectedButton == 1 ? 0 : 1;
  Renderer::IncludeBlock(arrow, arrowPosition[m_selectedButton], 3);
  Renderer::RemoveBlock(arrow, arrowPosition[!m_selectedButton], 3);
}