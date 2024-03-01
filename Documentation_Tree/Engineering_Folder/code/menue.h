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
     * @brief draws the menue on next OS-Tick
     */
    void DrawMenue()
    {
      memcpy(screen, m_titleSprite, sizeof(int32_t) * 32);
      m_selectedButton = 0;
    }
    /**
     * @brief redraws the menue
     */
    virtual void RefreshMenue() = 0;
    /**
     * @brief executes the functionallity of the currently focused button
     */
    virtual void PushButton() = 0;
    /**
     * @brief selects the next button
     */
    virtual void ButtonSelect() = 0;
  
  protected:
    uint8_t m_selectedButton = 0;
    int32_t* m_titleSprite;
};

#endif
