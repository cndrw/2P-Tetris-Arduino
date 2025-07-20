#include "constants.h"
#include "vector.h"

namespace Renderer
{
  void ShiftAll(uint8_t sendToAdress, uint8_t data)
  {
    // digitalWrite(CS, LOW);
    PORTB &= ~(1 << PB0); // CS LOW
    for (int i = 0; i < SIZE; i++)
    {
      SPI.transfer(sendToAdress);
      SPI.transfer(data);
    }
    // digitalWrite(CS, HIGH);
    PORTB |= (1 << PB0); // CS HIGH
  }

  void SetupScreen()
  {
    ShiftAll(0x0f, 0x00); //display test register - test mode off
    ShiftAll(0x0b, 0x07); //scan limit register - display digits 0 thru 7
    ShiftAll(0x0c, 0x01); //shutdown register - normal operation
    ShiftAll(0x0a, 0x00); //intensity register - max brightness
    ShiftAll(0x09, 0x00); //decode mode register - No decode
  }

  void DrawScreen()
  {
    for (uint8_t i = 0; i < ROWS; i++)
    {
      PORTB &= ~(1 << PB0); // CS LOW
      for (uint8_t j = 0; j < SIZE; j++)
      {
        uint8_t data = screen[i + (j / 4) * 8] >> ((6 - ((j % 4) * 2)) * 4);

#if SIMULATION
        data = ((data >> 1) & 0x55) | ((data << 1) & 0xAA);
        data = ((data >> 2) & 0x33) | ((data << 2) & 0xCC);
        data = (data >> 4) | (data << 4);
#endif
        // first define which row then send data
        SPI.transfer(i + 1);
        SPI.transfer(data);
      }
    PORTB |= (1 << PB0); // CS HIGH
    }
  }

  void IncludeBlock(Vector points[], Vector anchorPoint, int length)
  {
    for (uint8_t i = 0; i < length; i++)
    {
      int32_t& previousRow = screen[points[i].y + anchorPoint.y];
      previousRow |= ((int32_t)1 << (31 - (anchorPoint.x + points[i].x)));
    }  
  }

  void RemoveBlock(Vector points[], Vector anchorPoint, int length)
  {
    for (uint8_t i = 0; i < length; i++)
    {
      // int32_t& previousRow = screen[points[i].y + (anchorPoint.y - 1)];
      int32_t& previousRow = screen[points[i].y + anchorPoint.y];
      previousRow &= ~((int32_t)1 << (31 - (anchorPoint.x + points[i].x)));
    }
  }

  void IncludeRows(int32_t rows[], uint8_t insertAt, uint8_t length)
  {
    memcpy(screen + insertAt, rows, sizeof(int32_t) * length);
  }

  void IncludeRowsAdditive(int32_t rows[], uint8_t insertAt, uint8_t length)
  {
    for (uint8_t i = 0; i < length; i++)
    {
      screen[insertAt + i] |= rows[i];
    }
  }

  void ClearRows(uint8_t from, uint8_t to)
  {
    for (uint8_t i = from; i < to; i++)
    {
      screen[i] = 0;
    }
  }

  void ClearScreen()
  {
    for (uint8_t i = 0; i < 32; i++)
    {
      screen[i] = 0;
    }
  }
}
