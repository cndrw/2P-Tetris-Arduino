#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "retris_game.h"
#include "constants.h"
#include "vector.h"

/**
 * @class GameManager
 * @brief manages the gameplay of RetrisOS
 */
class GameManager : public Process
{
  public:
    /**
     * @brief initializes the game session(s)
     * @param playerCount how many game instances will be started (max. 2)
     */
    void Init(uint8_t playerCount);
    /**
     * @brief updates each game instance and the music
     */
    void Update();
#if SIMULATION
    /**
     * @brief directs the pressed buttons to the game instances
     * @param pressedButton1 pressed button from controller 1
     * @param pressedButton2 pressed button from controller 2
     */
    void Input(uint8_t pressedButton1, uint8_t pressedButton2);
#endif
    /**
     * @brief saves and freezes the game instances
     */
    void Freeze(bool freeze);

  private:
    /**
     * @brief saves the current state of the playing field
     */
    void SaveGameState();
    /**
     * @brief loads the saved game field state
     */
    void LoadGameState();

  private:
    RetrisGame m_games[2] = { RetrisGame(), RetrisGame() };
    Vector m_gamePositions[2] = { {1, 10}, {19, 10} };
    int32_t m_savedFields[GAME_HEIGHT] = {0};
    uint8_t m_playerCount = 1;
};

#endif
