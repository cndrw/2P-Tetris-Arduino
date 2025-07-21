#include "retris_game.h"
#include "audio.h"
#include "config.h"
#include "game_manager.h"
#include "retris_os.h"

#if !SIMULATION
#include "input.h"
#endif

void GameManager::Init(uint8_t playerCount)
{
  // redraw the screen in order to have an empty
  // one while the intro sequence is happening
  Renderer::DrawScreen();

  // intro sequence
  HW::lcd.setCursor(0, 0);
  HW::lcd.print("Auf die Bloecke,");
  delay(1000);
  HW::lcd.setCursor(3, 1);
  HW::lcd.print("fertig, ");
  delay(1000);
  HW::lcd.print("LOS!");
  delay(100);
  HW::lcd.clear();

  switch (playerCount)
  {
    case GAME_OPT_1P:
    case GAME_OPT_2P:
      m_playerCount = playerCount;
      break;

    case GAME_OPT_LAST:
      // m_playerCount will be whatever it was last time
      break;
  }
#if !SIMULATION
  Input::SetControllerCount(m_playerCount);
#endif
  for (uint8_t i = 0; i < m_playerCount; i++)
  {
    m_games[i].Init(m_gamePositions[i], m_playerCount);
  }

  if (config.musicEnabled)
  {
    Audio::PlayAudio(AUDIO_KOROBEINIKI, true);
  }
}

void GameManager::Update()
{
#if !SIMULATION
  // switch to the pause menu is handled by the game manager
  if (Input::GetButtonDown(CONTROLLER_1, BUTTON_START) || 
      Input::GetButtonDown(CONTROLLER_1, BUTTON_SELECT))
  {
    Audio::StopAudio();
    retris.FreezeCurrentProcess(SYS_PROCESS_MENUE, PAUSE_MENUE);
  }
#endif

  uint8_t changeCondition = 0;
  for (uint8_t i = 0; i < m_playerCount; i++)
  {
    m_games[i].Update();
    // the finished game state has the value 4 so 4 * playerCount must be 4 (for one player)
    // or 8 (for two player)
    changeCondition += m_games[i].GetGameState();
  }

  if (changeCondition == GAME_STATE_FINISHED * m_playerCount)
  {
    Audio::PlayAudio(AUDIO_GAME_OVER);
    retris.ChangeProcess(SYS_PROCESS_MENUE, DEATH_MENUE);
  
    CheckForNewHighscore();
  }
}

#if SIMULATION
void GameManager::Input(uint8_t pressedButton1, uint8_t pressedButton2)
{
  if (pressedButton1 == BUTTON_START)
  {
    Audio::StopAudio();
    retris.FreezeCurrentProcess(SYS_PROCESS_MENUE, PAUSE_MENUE);
  }

  m_games[0].ProcessInput(pressedButton1);
  if (m_playerCount == 2)
  {
    m_games[1].ProcessInput(pressedButton2);
  }
}
#endif

void GameManager::Freeze(bool freeze)
{
  if (freeze)
  {
    SaveGameState();
  }
  else
  {
    LoadGameState();
    m_games[0].DrawGameField(m_playerCount);
    if (m_playerCount == 2)
    {
      m_games[1].DrawGameField(m_playerCount);
    }
  }
}

void GameManager::SaveGameState()
{
  // if 2-Player mode then both have the same y so, just get the y from game instance 1
  uint8_t row = m_games[0].GetGamePosition().y + 1; // get the first row from the game field (not border)
  memcpy(m_savedFields, screen + row, sizeof(int32_t) * GAME_HEIGHT);
}

void GameManager::LoadGameState()
{
  uint8_t row = m_games[0].GetGamePosition().y + 1;
  Renderer::IncludeRows(m_savedFields, row, GAME_HEIGHT);
}

void GameManager::CheckForNewHighscore()
{
  for (uint8_t i = 0; i < m_playerCount; i++)
  {
    uint32_t& currentScore = m_games[i].GetCurrentScore();
    if (currentScore > config.highscore)
    {
      config.highscore = currentScore;
      config.SaveConfig();
    }
  }
}

