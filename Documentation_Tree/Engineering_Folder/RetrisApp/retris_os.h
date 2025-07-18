#ifndef RETRIS_OS_H
#define RETRIS_OS_H

#include "system_process.h"

#define MAX_PROCESS_SIZE 2

#define SYS_PROCESS_GAME 0
#define SYS_PROCESS_MENUE 1

/**
 * @brief Controls which process is currently running
 */
class RetrisOS
{
  public:
    RetrisOS() {}
    /**
     * @brief Adds a process to the internal process list
     * @param p_process The process that will be added
     */
    void AddProcess(Process* p_process);
    /**
     * @brief Updates the Retris system and the current process
     * @details Reads in the controller inputs
     */
    void UpdateSystem();
    /**
     * @brief Changes the currently running process
     * @param process The process that shall be executed
     * @param option Additional option for the initialization of the process
     */
    void ChangeProcess(uint8_t process, uint8_t option);
    /**
     * @brief Freezes the currently running process
     * @param newProcess The new process that will be executed instead
     * @param option Initialization option for the process
     */
    void FreezeCurrentProcess(uint8_t newProcess, uint8_t option);
    /**
     * @brief Unfreezes the currently frozen process
     * @details There can only one frozen process at a time
     */
    void UnFreezeProcess(); 


  private:
    Process* mp_processes[MAX_PROCESS_SIZE];
    uint8_t m_processCount = 0;
    uint8_t m_currentProcess = 0;
    uint8_t m_frozenProcess = 0;

}retris;

#endif
