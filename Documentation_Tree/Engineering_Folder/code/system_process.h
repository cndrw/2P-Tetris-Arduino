#ifndef SYSTEM_PROCESS_H
#define SYSTEM_PROCESS_H

#include "constants.h"

/**
 * @class Process
 * @brief application unit that can be run by the RetrisOS
 */
class Process
{
  public:
    /**
     * @brief updates the process
     */
    virtual void Update() = 0;
    /**
     * @brief initializes the process (start up)
     * @param option additional options for the initialization
     */
    virtual void Init(uint8_t option) = 0;
#if SIMULATION
    /**
     * @brief gathers the current controller inputs (simulation)
     * @param button1 input of controller 1
     * @param button2 input of controller 2
     */
    virtual void Input(uint8_t button1, uint8_t button2) = 0;
#endif
    /**
     * @brief freezes the process
     * @detials can be discarded or unfrozen by an other process
     * @param freeze if true -> process freezes
     * @param freeze if false -> process unfreezes
     */
    virtual void Freeze(bool freeze) = 0;
};

#endif
