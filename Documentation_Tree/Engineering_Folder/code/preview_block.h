#ifndef PREVIEW_BLOCK_H
#define PREVIEW_BLOCK_H

#include "vector.h"
#include "constants.h"

/**
 * @brief handles the preview field 
*/
class PreviewBlock
{
  public:
    /**
     * @brief updates the preview
     * @param name name of the block that will be previewed
     */
    void UpdatePreview(uint8_t name);
    /**
     * @brief draws the border of the preview
     */
    void DrawBorder();

  private:
    /**
     * @brief clears the preview (not the borders)
     */
    void ClearPreview();

  public:
    Vector borderPosition = {0, 0};
  
  private:
    Vector previewBlock[BLOCK_LENGTH];
    const Vector positionTable[7] = { {4, 4}, {6, 4}, {5, 3}, {4, 4}, {6, 4}, {4, 3}, {6, 4} };
    uint8_t m_width = 12; // 10
    uint8_t m_height = 10; // 12
};

#endif

