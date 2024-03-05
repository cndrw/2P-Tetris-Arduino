#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "retris_game.h"
#include "constants.h"
#include "vector.h"

/**
 * @class GameManager
 * @brief Manages the gameplay of up to two RetrisGame instances
 */
class GameManager : public Process
{
  public:
    /**
     * @brief Initializes the game session(s)
     * @param playerCount How many game instances will be started (max. 2)
     */
    void Init(uint8_t playerCount);
    /**
     * @brief Updates each game instance
     */
    void Update();
#if SIMULATION
    /**
     * @brief Directs the pressed buttons to the game instances (simulation)
     * @param pressedButton1 Pressed button from controller 1
     * @param pressedButton2 Pressed button from controller 2
     */
    void Input(uint8_t pressedButton1, uint8_t pressedButton2);
#endif
    /**
     * @brief Saves the current state of the game field and freezes the game instances
     */
    void Freeze(bool freeze);

  private:
    /**
     * @brief Saves the current state of the playing field
     */
    void SaveGameState();
    /**
     * @brief Loads the saved game field state
     */
    void LoadGameState();

  private:
    RetrisGame m_games[2] = { RetrisGame(), RetrisGame() };
    Vector m_gamePositions[2] = { {1, 10}, {19, 10} };
    int32_t m_savedFields[GAME_HEIGHT] = {0};
    uint8_t m_playerCount = 1;
};

#endif
