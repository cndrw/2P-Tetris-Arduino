#include "settings_menue.h"
#include "config.h"
#include "audio.h"
#include "renderer.h"
#include "input.h"

#define MUSIC_LABEL 0
#define FAST_FALL_LABEL 1

void SettingsMenue::ButtonSelect()
{
  if (Input::GetButtonDown(CONTROLLER_1, BUTTON_START))
  {
    Audio::PlayAudio(AUDIO_BUTTON_PRESS);
    retris.ChangeProcess(SYS_PROCESS_MENUE, MAIN_MENUE);
    if (settingsChanged)
    {
      config.SaveConfig();
      settingsChanged = false;
    }
    return;
  }


  if (Input::GetButtonDown(CONTROLLER_1, BUTTON_UP) ||
      Input::GetButtonDown(CONTROLLER_1, BUTTON_DOWN))
  {
    Audio::PlayAudio(AUDIO_BUTTON_SWITCH);
    m_selectedButton = !m_selectedButton;
    RefreshMenue();
  }

  if (Input::GetButtonDown(CONTROLLER_1, BUTTON_A))
  {
    Audio::PlayAudio(AUDIO_BUTTON_PRESS);

    switch (m_selectedButton)
    {
      case MUSIC_LABEL:
        config.musicEnabled = !config.musicEnabled;
        break;
      case FAST_FALL_LABEL:
        config.fastFallEnabled = !config.fastFallEnabled;
        break;
    }
    settingsChanged = true;
    RefreshMenue();
  }
}

void SettingsMenue::RefreshMenue()
{

  // redraw the menue (without on/off labels)
  memcpy(screen, m_titleSprite, sizeof(int32_t) * 32);

  // change selected setting 

  // Render everything
  Renderer::IncludeBlock(arrow, arrowPosition[m_selectedButton], 3);
  Renderer::RemoveBlock(arrow, arrowPosition[!m_selectedButton], 3);

  Renderer::IncludeRowsAdditive(labels[config.musicEnabled], labelPositions[MUSIC_LABEL], 5);
  Renderer::IncludeRowsAdditive(labels[config.fastFallEnabled], labelPositions[FAST_FALL_LABEL], 5);
}
