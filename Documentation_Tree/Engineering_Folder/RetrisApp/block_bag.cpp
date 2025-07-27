#include "block_bag.h"
#include "Arduino.h"

void BlockBag::Init()
{
  ShuffleBag(m_activeBag);
  ShuffleBag(m_bufferBag);
}

void BlockBag::ShuffleBag(uint8_t bag[BAG_SIZE])
{
  for (int i = BAG_SIZE - 1; i > 0; i--) 
  {
    int j = random(i);
    
    int temp = bag[i];
    bag[i] = bag[j];
    bag[j] = temp;
  }
}

uint8_t BlockBag::GetNextBlock()
{
  m_counter = m_counter % BAG_SIZE;
  uint8_t nextBlock = m_activeBag[m_counter];
  m_counter++;

  if (m_counter == BAG_SIZE)
  {
    memcpy(m_activeBag, m_bufferBag, sizeof(uint8_t) * BAG_SIZE);
    ShuffleBag(m_bufferBag);
  }

  return nextBlock;
}