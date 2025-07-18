#include "vector.h"
#include "constants.h"
#include "preview_block.h"

void PreviewBlock::UpdatePreview(uint8_t name)
{
  ClearPreview();

  memcpy(previewBlock, previewBlockShape[name], sizeof(Vector) * BLOCK_LENGTH);
  for (int i = 0; i < BLOCK_LENGTH; i++)
  {
    previewBlock[i] *= 2;
  }

  Vector position = borderPosition + positionTable[name];
  Renderer::IncludeBlock(previewBlock, position, BLOCK_LENGTH);
  position.x++;
  Renderer::IncludeBlock(previewBlock, position, BLOCK_LENGTH);
  position.y++;
  Renderer::IncludeBlock(previewBlock, position, BLOCK_LENGTH);
  position.x--;
  Renderer::IncludeBlock(previewBlock, position, BLOCK_LENGTH);
  position.y--;
}

void PreviewBlock::DrawBorder()
{
  int32_t horizontal = 0x00000FFF;
  int32_t vertical = 0x000000801;

  uint8_t offset = 32 - borderPosition.x - m_width;

  horizontal <<= offset;
  vertical <<= offset;

  screen[borderPosition.y] |= horizontal;
  screen[borderPosition.y + m_height -1] |= horizontal;

  for (int i = 0; i < m_height -1; i++)
  {
    screen[i + borderPosition.y + 1] |= vertical;
  }
}

void PreviewBlock::ClearPreview()
{
  for (int i = 0; i < m_height - 2; i++)
  {
    int32_t previewMask = 0x000003FF;
    // +1 to prevent erasing the border
    screen[i + borderPosition.y + 1] &= ~(previewMask << (32 - m_width - borderPosition.x + 1));
  }
}
  
