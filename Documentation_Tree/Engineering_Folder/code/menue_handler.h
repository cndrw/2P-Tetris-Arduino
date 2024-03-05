#ifndef MENUE_HANDLER_H
#define MENUE_HANDLER_H

#include "menue.h"
#include "main_menue.h"

/**
 * @class MenueHandler
 * @brief Controls the currently running menue and can change between up to 3 menus
 */
class MenueHandler : public Process
{
  public:
    /**
     * @brief Adds a menu to the internal managed menues
     * @param p_menue Menu that will be added
     */
    void AddMenue(Menue* p_menue);
    /**
     * @brief Initializes the menu
     * @param menue The menu that will be initialized
     */
    void Init(uint8_t menue);
    /**
     * @brief updates the currently running menu
     */
    void Update();
#if SIMULATION
    /**
     * @brief Directs the currently pressed button to the currently running menu (simulation)
     * @param pressedButton Button that got pressed by controller 1
     */
    void Input(uint8_t pressedButton, uint8_t);
#endif
    /**
     * @brief Freezes the currently running menu
     * @details Functionality not needed, therefore no implementation
     */
    void Freeze(bool) {}

  private:
    Menue* mp_menues[3];
    uint8_t m_currentMenue = 0;
};

#endif
