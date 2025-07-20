#ifndef RENDERER_H
#define RENDERER_H

#include "constants.h"
#include "vector.h"

namespace Renderer
{
  /**
   * @brief function for setting up all matrices at once
   * @param sentToAdress adress of the register
   * @param data data that will be set in the register
  */
  void ShiftAll(uint8_t sendToAdress, uint8_t data);
  /**
   * @brief sets up the led matrices by writing to their registers
  */
  void SetupScreen();
  /**
   * @brief draws the current state of screen to the matrix 
   */
  void DrawScreen();
  /**
   * @brief draws a block to the screen
   * @param points points that make up the block
   * @param anchorPoint coordinates where the block will be placed
   * @param length how many points the block has
   */
  void IncludeBlock(Vector points[], Vector anchorPoint, int length);
  /**
   * @brief removes a block from the screen
   * @param points points that make up the block
   * @param anchorPoint coordinates where the block will be removed
   * @param length how many points the block has
   */
  void RemoveBlock(Vector points[], Vector anchorPoint, int length);
  /**
   * @brief adds whole rows to the screen
   * @details can only add contigious rows 
   * @param rows collection of rows that will be added
   * @param insertAt at which row the insertion starts
   * @param length how many rows 
   */
  void IncludeRows(int32_t rows[], uint8_t insertAt, uint8_t length);
  /**
   * @brief adds whole rows additive to the screen
   * @details can only add contigious rows  
   * @details additive means that only the ones can be added  
   * @param rows collection of rows that will be added
   * @param insertAt at which row the insertion starts
   * @param length how many rows 
   */
  void IncludeRowsAdditive(int32_t rows[], uint8_t insertAt, uint8_t length);
  /**
   * @brief removes all rows between to rows (inlcusiv)
   * @details can only remove contigious rows 
   * @param from start row
   * @param to end row
   */
  void ClearRows(uint8_t from, uint8_t to);
  /**
   * @brief clears the whole screen
   */
  void ClearScreen();
}

#endif
