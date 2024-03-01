#ifndef BLOCK_H
#define BLOCK_H

#include "vector.h"
#include "constants.h"

/**
 * @brief A tetris block that can be moved and rotated
*/
class Block
{
  public:
    /**
     * @brief changes which specific block the object currently is
     * @param blockShape which Block it will be
     * @param name name of the new Block
     * @param startPosition where the Block will appear on the screen
     */
    void Create(const Vector blockShape[], const uint8_t name, const Vector startPosition);
    /**
     * @brief Rotates the block 90 degree clockwise
     * @details Not rendering
     */
    void Rotate();
    /**
     * @brief Moves the block one to the right
     * @details Not rendering
    */
    void MoveRight();
    /**
     * @brief Moves the block one to the left
     * @details Not rendering
    */
    void MoveLeft();
    /**
     * @brief Moves the block one down 
     * @details Not rendering
    */
    void MoveDown();

  public:
    Vector points[BLOCK_LENGTH];
    Vector position = {0,0};
    uint8_t blockName = 0;
};

#endif
