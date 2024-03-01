#include "retris_os.h"
#include "constants.h"

#if !SIMULATION
#include "input.h"
#endif

void RetrisOS::AddProcess(Process* p_process)
{
  mp_processes[m_processCount] = p_process;
  m_processCount++;
}

void RetrisOS::ChangeProcess(uint8_t process, uint8_t option)
{
  Renderer::ClearScreen();
  mp_processes[process]->Init(option);
  m_currentProcess = process;
}

#if SIMULATION
bool rightPressed = false;
bool leftPressed = false;
bool rotatePressed = false;
bool downPressed = false;
bool startPressed = false;
#endif

void RetrisOS::UpdateSystem()
{
#if SIMULATION
  static uint8_t button = 0;
  if (digitalRead(2) == LOW && !rightPressed)
  {
    button = 1;
    mp_processes[m_currentProcess]->Input(button, button);
    rightPressed = true;
  }
  else if (digitalRead(2) == HIGH && rightPressed)
  {
    rightPressed = false;
    button = 0;
  }

  if (digitalRead(3) == LOW && !leftPressed)
  {
    button = 2;
    mp_processes[m_currentProcess]->Input(button, button);
    leftPressed = true;
  }
  else if (digitalRead(3) == HIGH && leftPressed)
  {
    leftPressed = false;
    button = 0;
  }

  if (digitalRead(5) == LOW && !rotatePressed)
  {
    button = 3;
    mp_processes[m_currentProcess]->Input(button, button);
    rotatePressed = true;
  }
  else if (digitalRead(5) == HIGH && rotatePressed)
  {
    rotatePressed = false;
    button = 0;
  }

  if (digitalRead(4) == LOW && !downPressed)
  {
    button = 4;
    mp_processes[m_currentProcess]->Input(button, button);
    downPressed = true;
  }
  else if (digitalRead(4) == HIGH && downPressed)
  {
    downPressed = false;
    button = 0;
    mp_processes[m_currentProcess]->Input(button, button);
  }

  if (digitalRead(6) == LOW && !startPressed)
  {
    button = 5;
    mp_processes[m_currentProcess]->Input(button, button);
    startPressed = true;
  }
  else if (digitalRead(6) == HIGH && startPressed)
  {
    startPressed = false;
    button = 0;
    // mp_processes[m_currentProcess]->Input(button, button);
  }
#else
  Input::ReadControllerInputs();
#endif

  mp_processes[m_currentProcess]->Update();
}

// replaces the current process with the frozen one
void RetrisOS::UnFreezeProcess()
{
  Renderer::ClearScreen();
  mp_processes[m_frozenProcess]->Freeze(false);
  // a frozen process doesn't need to be initalized again, it'll will just continue
  m_currentProcess = m_frozenProcess;
  m_frozenProcess = 0;
}

void RetrisOS::FreezeCurrentProcess(uint8_t newProcess, uint8_t option)
{
  m_frozenProcess = m_currentProcess;
  mp_processes[m_frozenProcess]->Freeze(true);

  // start the new Process
  mp_processes[newProcess]->Init(option);
  m_currentProcess = newProcess;
}
