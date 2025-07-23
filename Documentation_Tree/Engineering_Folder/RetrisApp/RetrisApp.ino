#include <SPI.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include "retris_os.h"
#include "renderer.h"
#include "constants.h"
#include "retris_game.h"
#include "game_manager.h"
#include "menue_handler.h"
#include "main_menue.h"
#include "death_menue.h"
#include "pause_menue.h"
#include "settings_menue.h"
#include "audio.h"
#include "config.h"

void WatchdogSetup()
{
  cli();
  asm("WDR"); // reset watchdog
  WDTCSR |= (1 << WDCE) | (1 << WDE); // watchdog change enable - as demanded by the datasheet
  WDTCSR = (1 << WDE) | (1 << WDP3); // after 4s - system reset
  sei();
}

GameManager gameManager;
MenueHandler menueHandler;
MainMenue mainMenue;
DeathMenue deathMenue;
PauseMenue pauseMenue;
SettingsMenue settingsMenue;


void setup() {
  Serial.begin(9600);
  // set DIN (PB2), CLK (PB1) and CS (PB0) for matrices to output
  DDRB |= (1 << PB1) | (1 << PB2) | (1 << PB0);
  SPI.beginTransaction(SPISettings(16000000, MSBFIRST, SPI_MODE0));

  // set up everything
  Audio::Setup();
  Renderer::SetupScreen();
  HW::lcd.init();
  HW::lcd.backlight();
  // config.LoadConfig();
  WatchdogSetup();
#if !SIMULATION
  Input::SetupPins();
#endif

  // add process to the executing force
  retris.AddProcess(&gameManager);
  retris.AddProcess(&menueHandler);

  // add all menu to the handler
  menueHandler.AddMenue(&mainMenue);
  menueHandler.AddMenue(&deathMenue);
  menueHandler.AddMenue(&pauseMenue);
  menueHandler.AddMenue(&settingsMenue);

  // start with the main menu
  retris.ChangeProcess(SYS_PROCESS_MENUE, MAIN_MENUE);

#if SIMULATION
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
#endif
}

void loop()
{
  retris.UpdateSystem();
  asm("WDR"); // reset watchdog
  delay(10);
}

// TODO:
// - hold mechanic nur bei einzelspieler
// - gedrückt halten von links/rechts -> sliden links/rechts 
// - block erst "gesetz" wenn kein input mehr kommt (links/rechts/rotation)

// Wenn ich flashen kann
// - settings menue testen
// - speichern von daten mit EEPROM testen
// - fast fall testen
// - fast fall visual pwm ausprobieren
// - wird highscore korrekt aktualisiert?
// - wird nur config gespeichert, wenn sich etwas geändert hat?
