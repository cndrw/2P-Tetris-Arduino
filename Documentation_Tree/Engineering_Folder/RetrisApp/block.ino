#include "vector.h"
#include "constants.h"
#include "renderer.h"
#include "block.h"

void Block::Create(const Vector blockShape[], const uint8_t name, const Vector startPosition)
{
  memcpy(points, blockShape, sizeof(Vector) * BLOCK_LENGTH);
  blockName = name;
  position = startPosition;
  Renderer::IncludeBlock(points, position, BLOCK_LENGTH);
}

void Block::Rotate()
{
  switch(blockName)
  {
    case I:
      for (int i = 0; i < BLOCK_LENGTH; i++)
      {
        Vector temp = points[i];
        points[i].x = temp.y;
        points[i].y = temp.x;
      }
      break;

    case O:
      break;

    default:
      for (int i = 0; i < BLOCK_LENGTH; i++)
      {
        Vector temp = points[i];
        points[i].x = -temp.y;
        points[i].y = temp.x;
      }
      break;
  }
}

void Block::MoveRight()
{
  position.x++;
}

void Block::MoveLeft()
{
  position.x--;
}

void Block::MoveDown()
{
  position.y++;
}
