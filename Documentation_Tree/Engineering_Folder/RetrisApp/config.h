#ifndef CONFIG_H
#define CONFIG_H

namespace HW {
    #include <EEPROM.h>
}

#define MUSIC_ENABLED_ADDR 0
#define FAST_FALL_ENABLED_ADDR 1 * sizeof(bool)

struct Config {
    bool musicEnabled = true; 
    bool fastFallEnabled = true;

    void SaveConfig()
    {
        // EEPROM.put(MUSIC_ENABLED_ADDR, musicEnabled);
        // EEPROM.put(FAST_FALL_ENABLED_ADDR, fastFallEnabled);
    }

    void LoadConfig()
    {
        // EEPROM.get(MUSIC_ENABLED_ADDR, musicEnabled);
        // EEPROM.get(FAST_FALL_ENABLED_ADDR, fastFallEnabled);
    }
}config;


#endif // CONFIG_H