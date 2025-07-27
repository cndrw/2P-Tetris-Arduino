#ifndef CONFIG_H
#define CONFIG_H

#include <EEPROM.h>

#define MUSIC_ENABLED_ADDR 0
#define FAST_DROP_ENABLED_ADDR 1 * sizeof(bool)
#define HIGH_SCORE_ADDR 2 * sizeof(bool)

struct Config
{
    bool musicEnabled = true; 
    bool fastDropEnabled = true;
    uint32_t highscore = 0;

    void SaveConfig()
    {
        EEPROM.put(MUSIC_ENABLED_ADDR, musicEnabled);
        EEPROM.put(FAST_DROP_ENABLED_ADDR, fastDropEnabled);
        EEPROM.put(HIGH_SCORE_ADDR, highscore);
    }

    void LoadConfig()
    {
        EEPROM.get(MUSIC_ENABLED_ADDR, musicEnabled);
        EEPROM.get(FAST_DROP_ENABLED_ADDR, fastDropEnabled);
        EEPROM.get(HIGH_SCORE_ADDR, highscore);
    }
}config;


#endif // CONFIG_H