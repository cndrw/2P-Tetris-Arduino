#include "settings_menue.h"
#include "config.h"
#include "audio.h"
#include "renderer.h"

#define MUSIC_LABEL 0
#define FAST_FALL_LABEL 1

void SettingsMenue::PushButton()
{
  Audio::PlayAudio(AUDIO_BUTTON_PRESS);

  switch (m_selectedButton)
  {
    case MUSIC_LABEL:
      config.musicEnabled = !config.musicEnabled;
      Renderer::IncludeRowsAdditive(labels[config.musicEnabled], labelPositions[MUSIC_LABEL], 5);
      break;
    case FAST_FALL_LABEL:
      config.fastFallEnabled = !config.fastFallEnabled;
      Renderer::IncludeRowsAdditive(labels[config.fastFallEnabled], labelPositions[FAST_FALL_LABEL], 5);
      break;
  }
}

void SettingsMenue::ButtonSelect()
{
  Audio::PlayAudio(AUDIO_BUTTON_SWITCH);

  m_selectedButton = m_selectedButton == 1 ? 0 : 1;
  Renderer::IncludeBlock(arrow, arrowPosition[m_selectedButton], 3);
  Renderer::RemoveBlock(arrow, arrowPosition[!m_selectedButton], 3);
}