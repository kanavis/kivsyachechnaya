/* 
* Storage header
* 
* Storage structure:
*   0-6      (8)  MAGIC WORD "MAGIC!"
*   7-104    (98) wifi credentials
*   105-111  (6)  terrarium settings
*/
#pragma once

#include <cstdint>

#include "settings_cls/constraints.h"


#define STORAGE_MAGIC "MAGIC!"
#define STORAGE_SIZE 512
#define WIFI_ADDR 7
#define TERRARIUM_ADDR 105


class Storage {
private:
    static bool _initialized;
    static const size_t wifi_ssid_address = WIFI_ADDR;
    static const size_t wifi_password_address = WIFI_ADDR + 1 + WIFI_MAX_SSID_LENGTH;
    static const size_t terrarium_temp_low_address = TERRARIUM_ADDR;
    static const size_t terrarium_temp_high_address = TERRARIUM_ADDR + sizeof(uint16_t);
    static const size_t terrarium_hum_low_address = TERRARIUM_ADDR + sizeof(uint16_t) * 2;
    static const size_t terrarium_hum_high_address = TERRARIUM_ADDR + sizeof(uint16_t) * 2 + sizeof(uint8_t);
    static void _init();
public:
    static bool hasMagic();
    static void setMagic();
    static void saveSystemSettings();
    static void loadSystemSettings();
    static void saveTerrariumSettings();
    static void loadTerrariumSettings();
};
