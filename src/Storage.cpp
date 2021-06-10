/* Storage implementation */
#include <cstdint>
#include "EEPROM.h"

#include "globals.h"
#include "kivsyachechnaya.h"

#include "Storage.h"


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
void Storage::saveSystemSettings() {
    Storage::_init();
    EEPROM.writeString(Storage::wifi_ssid_address, String(systemSettings->getWifiSSID().c_str()));
    EEPROM.writeString(Storage::wifi_password_address, String(systemSettings->getWifiPassword().c_str()));
    EEPROM.commit();
}

void Storage::loadSystemSettings() {
    Storage::_init();
    std::string ssid = std::string(EEPROM.readString(Storage::wifi_ssid_address).c_str());
    std::string password = std::string(EEPROM.readString(Storage::wifi_password_address).c_str());
    systemSettings = new SystemSettings(ssid, password);
}


/* Terrarium */
void Storage::saveTerrariumSettings() {
    Storage::_init();
    EEPROM.writeUShort(Storage::terrarium_temp_low_address, terrariumSettings->getTempLow());
    EEPROM.writeUShort(Storage::terrarium_temp_high_address, terrariumSettings->getTempHigh());
    EEPROM.writeUChar(Storage::terrarium_hum_low_address, terrariumSettings->getHumLow());
    EEPROM.writeUChar(Storage::terrarium_hum_high_address, terrariumSettings->getHumHigh());
    EEPROM.commit();
}

void Storage::loadTerrariumSettings() {
    Storage::_init();
    uint16_t temp_low = EEPROM.readUShort(Storage::terrarium_temp_low_address);
    uint16_t temp_high = EEPROM.readUShort(Storage::terrarium_temp_high_address);
    uint8_t hum_low = EEPROM.readUChar(Storage::terrarium_hum_low_address);
    uint8_t hum_high = EEPROM.readUChar(Storage::terrarium_hum_high_address);
    terrariumSettings = new TerrariumSettings(temp_low, temp_high, hum_low, hum_high);
}
