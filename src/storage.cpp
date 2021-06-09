/* Storage implementation */
#include <cstdint>
#include "EEPROM.h"
#include "kivsyachechnaya.h"
#include "storage.h"

bool Storage::_initialized = false;


/* Magic */
void Storage::_init() {
    if (!Storage::_initialized) {
        EEPROM.begin(STORAGE_SIZE);
        Storage::_initialized = true;
    }
}

bool Storage::hasMagic() {
    Storage::_init();
    bool result = (std::string(EEPROM.readString(0).c_str()) == std::string(STORAGE_MAGIC));
    return result;
}

void Storage::setMagic() {
    Storage::_init();
    EEPROM.writeString(0, String(STORAGE_MAGIC));
}


/* Wifi */
void Storage::saveWifiCredentials(WifiCredentials* credentials) {
    Storage::_init();
    EEPROM.writeString(Storage::wifi_ssid_address, String(credentials->getSSID().c_str()));
    EEPROM.writeString(Storage::wifi_password_address, String(credentials->getPassword().c_str()));
    EEPROM.commit();
}

WifiCredentials* Storage::loadWifiCredentials() {
    Storage::_init();
    std::string ssid = std::string(EEPROM.readString(Storage::wifi_ssid_address).c_str());
    std::string password = std::string(EEPROM.readString(Storage::wifi_password_address).c_str());
    return new WifiCredentials(ssid, password);
}


/* Terrarium */
void Storage::saveTerrariumSettings(TerrariumSettings* settings) {
    Storage::_init();
    EEPROM.writeUShort(Storage::terrarium_temp_low_address, settings->getTempLow());
    EEPROM.writeUShort(Storage::terrarium_temp_high_address, settings->getTempHigh());
    EEPROM.writeUChar(Storage::terrarium_hum_low_address, settings->getHumLow());
    EEPROM.writeUChar(Storage::terrarium_hum_high_address, settings->getHumHigh());
    EEPROM.commit();
}

TerrariumSettings* Storage::loadTerrariumSettings() {
    Storage::_init();
    uint16_t temp_low = EEPROM.readUShort(Storage::terrarium_temp_low_address);
    uint16_t temp_high = EEPROM.readUShort(Storage::terrarium_temp_high_address);
    uint8_t hum_low = EEPROM.readUChar(Storage::terrarium_hum_low_address);
    uint8_t hum_high = EEPROM.readUChar(Storage::terrarium_hum_high_address);
    return new TerrariumSettings(temp_low, temp_high, hum_low, hum_high);
}
