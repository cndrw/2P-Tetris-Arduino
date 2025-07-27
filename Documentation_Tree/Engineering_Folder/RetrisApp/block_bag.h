#ifndef BLOCK_BAG_H
#define BLOCK_BAG_H

#include <stdint.h>

#define BAG_SIZE 7

class BlockBag
{
public:
  uint8_t GetNextBlock();
  void Init();

private:
  void ShuffleBag(uint8_t bag[BAG_SIZE]);

private:
  uint8_t m_activeBag[BAG_SIZE] = {0, 1, 2, 3, 4, 5, 6};
  uint8_t m_bufferBag[BAG_SIZE] = {0, 1, 2, 3, 4, 5, 6};
  uint8_t m_counter = 0;
};

#endif