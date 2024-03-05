#ifndef RETRIS_GAME_H
#define RETRIS_GAME_H

#include "vector.h"
#include "block.h"
#include "constants.h"
#include "renderer.h"
#include "preview_block.h"
#include "retris_os.h"

#if !SIMULATION
#include "input.h"
#endif

#define BASE_BLOCK_SPEED 30

#define GAME_STATE_PLAYING 0
#define GAME_STATE_ANIMATION 1
#define GAME_STATE_LOST 2
#define GAME_STATE_WAIT 3
#define GAME_STATE_FINISHED 4
/**
 * @brief Manages one single game unit and has alle the Tetris logic
 * implemented
 * @details Keeps track of which instance it is
*/
class RetrisGame
{
  public:
    RetrisGame();

    /**
     * @brief Initializes the game unit - drawing game field and creating first block
     * @details It also sets the random seed for the random block generation
     * @param startPosition Where the game field shall be placed (top-left point)
     * @param style How the game will appear (preview Block above or to the side of the game field)
     * 
    */
    void Init(Vector startPosition, uint8_t style);
#if SIMULATION
    void ProcessInput(uint8_t pressedButton);
#else
    /**
    * @brief checks if buttons are pressed and does the corresponding action
    */
    void ProcessInput();
#endif
    /**
     * @brief Function that gets called every game tick
     * @details An OS-Tick is a fraction of an game tick (depending on game speed)
    */
    void Update();
    /**
     * @brief Moves the current Block to the right by one
     * @details If the move to the right is not possible (collider on the right), the function will do nothing
    */
    void MoveRight();
    /**
     * @brief Moves the current Block to the left by one
     * @details If the move to the left is not possible (collider on the left), the function will do nothing
    */
    void MoveLeft();
    /**
     * @brief Rotates the current Block 90° clockwise
     * @details If the rotation is not possible the function will do nothing
    */
    void Rotate();
    /**
     * @brief Sets the rate of game ticks 
     * @details Low timeScale means faster game and high timeScale slower game
     * @param timeScale The number by which the OS-Tick gets divied by
    */
    void SetTimeScale(uint8_t timeScale);
    /**
     * @brief Draws the game field with the preview block
     * @param viewStyle The style of the game instance - preview  Block can be to the right or on top of the game field
    */
    void DrawGameField(uint8_t viewStyle);

    uint8_t GetGameState();
    Vector GetGamePosition();

  private:
      /**
       * @brief Validates if the given move is possible right now
       * @details It will internally perform the move on the current Block
       * @param move Which move will be checked
       * @return If true the move is valid
       * @return If false the move is invalid
      */
      bool ValidateMove(uint8_t move);
      /**
       * @brief Validates if the given move is possible right now
       * @details It will only check if the given points are intersecting with any collider
       * @param points Set of points that will be checked
       * @return If true the move is valid
       * @return If false the move is invalid
      */
      bool ValidateMove(Vector points[]);
      /**
       * @brief Checks if at least one full line is currently on the game field
       * @return If true a full line got detected
       * @return If false no full line got detected
      */
      bool CheckFullLine();
      /**
       * @brief Plays the clear animation for a full line (iterativly)
       * @details It also adjusts the level and speed accordingly as well as updating the score and spawing the new Block
       * 
      */
      void ClearAnimation();
      /**
       * @brief Updates the score and the LCD-Display
       * @details Calculates the points based on the amount of rows which got cleard and the current level
       * @param clearedRows How many lines got cleared
      */
      void UpdateScore(const uint8_t clearedRows);
      /**
       * @brief Plays the death (game over) animation (iterativly)
      */
      void DeathAnimation();
      /**
       * @brief Resets the game variables
       */
      void ResetGame();
      /**
       * @brief Activates the wait state, where the unit does nothing (inputs disabled)
       * @details After waiting, the unit will resume in the playing game state (with a newly created block)
       * @param waitTime Time that will be waited (Time = waitTime * 10ms)
      */
      void Wait(const uint8_t waitTime);
      /**
       * @brief Starts the procedure for spawning a new block
       * @details It checks if even a new block can be spawned - if the game state will be set to lost
       * @details If everything is fine, it will wait for 200ms (Wait(20))
       */
      void SpawnNewBlock();
      /**
       * @brief Creates a new block at the top of the field
       * @details Generates the next block and send it to the preview
      */
      void CreateBlock();

    private:
      Block m_currentBlock;
      uint8_t m_nextBlock = 0;
      Vector m_gamePosition = {0, 0}; // top-left of the playing field
      PreviewBlock m_previewBlock;
      uint8_t m_gameState = 0;
      int32_t m_fullLine = 0; // refrence integer for a full line
      int32_t m_fullLineTable = 0; // look up table for where a full line was detected
      uint8_t m_ticks = 0; // counter which counts OS-Ticks
      uint8_t m_timeScale = 30;
      uint16_t m_score = 0;
      uint8_t m_level = 0;
      uint8_t m_instanceCount = 0;
      uint16_t m_clearedLinesCount = 0;
      bool m_activeInput = true;
      uint8_t m_waitTime = 0;
      const Vector positionTable[7] = { {5, 2}, {5, 2}, {5, 2}, {5, 2}, {5, 2}, {5, 2}, {6, 2} };
      uint16_t m_baseSpeed = BASE_BLOCK_SPEED;
};

#endif
