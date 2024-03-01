#include "retris_game.h"
#include "audio.h"
#include "game_manager.h"
#include "retris_os.h"

#if !SIMULATION
#include "input.h"
#endif

void GameManager::Init(uint8_t playerCount)
{
  // redraw the screen in order to have an empty
  // one while the intro sequence is happening
  Renderer::DrawScreen(screen);

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

  for (uint8_t i = 0; i < m_playerCount; i++)
  {
    games[i].Init(gamePositions[i], m_playerCount);
  }
  Audio::PlayAudio(AUDIO_KOROBEINIKI, true);
}

void GameManager::Update()
{
#if !SIMULATION
  // switch to the pause menu is handled by the game manager
  if (Input::GetButtonDown(CONTROLLER_1, BUTTON_START))
  {
    Audio::StopAudio();
    retris.FreezeCurrentProcess(SYS_PROCESS_MENUE, PAUSE_MENUE);
  }
#endif

  uint8_t changeCondition = 0;
  for (uint8_t i = 0; i < m_playerCount; i++)
  {
    games[i].Update();
    // the finished game state has the value 4 so 4 * playerCount must be 4 (for one player)
    // or 8 (for two player)
    changeCondition += games[i].GetGameState();
  }

  if (changeCondition == GAME_STATE_FINISHED * m_playerCount)
  {
    Audio::PlayAudio(AUDIO_GAME_OVER);
    retris.ChangeProcess(SYS_PROCESS_MENUE, DEATH_MENUE);
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

  games[0].ProcessInput(pressedButton1);
  if (m_playerCount == 2)
  {
    games[1].ProcessInput(pressedButton2);
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
    games[0].DrawGameField(m_playerCount);
    if (m_playerCount == 2)
    {
      games[1].DrawGameField(m_playerCount);
    }
  }
}

void GameManager::SaveGameState()
{
  uint8_t row = 10 + 1;
  memcpy(m_savedFields, screen + row, sizeof(int32_t) * GAME_HEIGHT);
}

void GameManager::LoadGameState()
{
  Renderer::IncludeRows(m_savedFields, 11, GAME_HEIGHT);
}
