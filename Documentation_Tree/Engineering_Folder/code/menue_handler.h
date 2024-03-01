#ifndef MENUE_HANDLER_H
#define MENUE_HANDLER_H

#include "menue.h"
#include "main_menue.h"

/**
 * @class MenueHandler
 * @brief controls the currently running menue
 */
class MenueHandler : public Process
{
  public:
    /**
     * @brief adds a menu to the internal managed menues
     * @param p_menue menu that will be added
     */
    void AddMenue(Menue* p_menue);
    /**
     * @brief initializes the menu
     * @param menue the menu that will be initialized
     */
    void Init(uint8_t menue);
    /**
     * @brief updates the currently running menu
     */
    void Update();
#if SIMULATION
    /**
     * @brief directs the currently pressed button to the currently running menu (simulation)
     * @param pressedButton button that got pressed by controller 1
     */
    void Input(uint8_t pressedButton, uint8_t);
#endif
    /**
     * @brief freezes the currently running menu
     */
    void Freeze(bool) {}

  private:
    Menue* mp_menues[3];
    uint8_t m_currentMenue = 0;
};

#endif
