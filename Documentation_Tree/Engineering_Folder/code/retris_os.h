#ifndef RETRIS_OS_H
#define RETRIS_OS_H

#include "system_process.h"

#define MAX_PROCESS_SIZE 2

#define SYS_PROCESS_GAME 0
#define SYS_PROCESS_MENUE 1

/**
 * @brief controls the current running processes
 */
class RetrisOS
{
  public:
    RetrisOS() {}
    /**
     * @brief adds a process to the internal process list
     * @param p_process the process that will be added
     */
    void AddProcess(Process* p_process);
    /**
     * @brief updates the Retris system and the current process
     */
    void UpdateSystem();
    /**
     * @brief changes the currently running process
     * @param process the process that shall be executed
     * @param option additional option for the initialization of the process
     */
    void ChangeProcess(uint8_t process, uint8_t option);
    /**
     * @brief freezes the currently running process
     * @param newProcess the new process that will be executed instead
     * @param option initialization option for the process
     */
    void FreezeCurrentProcess(uint8_t newProcess, uint8_t option);
    // There can only be one frozen process at a time
    /**
     * @brief unfreezes the currently frozen process
     * @detail There can only one frozen process at a time
     */
    void UnFreezeProcess();


  private:
    Process* mp_processes[MAX_PROCESS_SIZE];
    uint8_t m_processCount = 0;
    uint8_t m_currentProcess = 0;
    uint8_t m_frozenProcess = 0;

}retris;

#endif
