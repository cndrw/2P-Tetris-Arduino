#ifndef SYSTEM_PROCESS_H
#define SYSTEM_PROCESS_H

#include "constants.h"

/**
 * @class Process
 * @brief Application unit that can be run by the RetrisOS
 */
class Process
{
  public:
    /**
     * @brief Updates the process
     */
    virtual void Update() = 0;
    /**
     * @brief Initializes the process (start up)
     * @param option Additional options for the initialization
     */
    virtual void Init(uint8_t option) = 0;
#if SIMULATION
    /**
     * @brief Gathers the current controller inputs (simulation)
     * @param button1 Input of controller 1
     * @param button2 Input of controller 2
     */
    virtual void Input(uint8_t button1, uint8_t button2) = 0;
#endif
    /**
     * @brief Can freezes or unfreeze the process
     * @details The frozen state can be discarded or unfrozen by RetrisOS
     * @param freeze If true -> process freezes
     * @param freeze If false -> process unfreezes
     */
    virtual void Freeze(bool freeze) = 0;
};

#endif
