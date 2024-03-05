#ifndef MENUE_H
#define MENUE_H

#include "vector.h"
#include "constants.h"

/**
* @brief Interface for a menu, a menu can be drawn, refreshed, the button can be selected 
* and the selected button can be pushed
*/
class Menue
{
  public:
    Menue(int32_t titleSprite[]) : m_titleSprite(titleSprite)
    {
    }

    virtual ~Menue() {}
    /**
     * @brief Writes the menue screen visual to the internal screen
     */
    void DrawMenue()
    {
      memcpy(screen, m_titleSprite, sizeof(int32_t) * 32);
      m_selectedButton = 0;
    }
    /**
     * @brief Redraws the menue
     */
    virtual void RefreshMenue() = 0;
    /**
     * @brief Executes the functionallity of the currently focused button
     */
    virtual void PushButton() = 0;
    /**
     * @brief Selects the next button
     */
    virtual void ButtonSelect() = 0;
  
  protected:
    uint8_t m_selectedButton = 0;
    int32_t* m_titleSprite;
};

#endif
