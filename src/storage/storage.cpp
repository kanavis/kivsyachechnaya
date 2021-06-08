/* Storage implementation */
#include <cstdint>
#include "EEPROM.h"
#include "storage.h"


/* Magic */
bool Storage::hasMagic() {
    EEPROM.begin(STORAGE_SIZE);
    bool result = (std::string(EEPROM.readString(0).c_str()) == std::string(STORAGE_MAGIC));
    EEPROM.end();
    return result;
}

void Storage::setMagic() {
    EEPROM.begin(STORAGE_SIZE);
    EEPROM.writeString(0, String(STORAGE_MAGIC));
    EEPROM.end();
}


/* Wifi */
void Storage::saveWifiCredentials(WifiCredentials& credentials) {
    EEPROM.begin(STORAGE_SIZE);
    EEPROM.writeString(Storage::wifi_ssid_address, String(credentials.getSSID().c_str()));
    EEPROM.writeString(Storage::wifi_password_address, String(credentials.getPassword().c_str()));
    EEPROM.end();
}

WifiCredentials Storage::loadWifiCredentials() {
    EEPROM.begin(STORAGE_SIZE);
    std::string ssid = std::string(EEPROM.readString(Storage::wifi_ssid_address).c_str());
    std::string password = std::string(EEPROM.readString(Storage::wifi_password_address).c_str());
    EEPROM.end();
    return WifiCredentials(ssid, password);
}


/* Terrarium */
void Storage::saveTerrariumSettings(TerrariumSettings& settings) {
    EEPROM.begin(STORAGE_SIZE);
    EEPROM.writeUShort(Storage::terrarium_temp_low_address, settings.getTempLow());
    EEPROM.writeUShort(Storage::terrarium_temp_high_address, settings.getTempHigh());
    EEPROM.writeUChar(Storage::terrarium_hum_low_address, settings.getHumLow());
    EEPROM.writeUChar(Storage::terrarium_hum_high_address, settings.getHumHigh());
    EEPROM.end();
}

TerrariumSettings Storage::loadTerrariumSettings() {
    EEPROM.begin(STORAGE_SIZE);
    uint16_t temp_low = EEPROM.readUShort(Storage::terrarium_temp_low_address);
    uint16_t temp_high = EEPROM.readUShort(Storage::terrarium_temp_high_address);
    uint8_t hum_low = EEPROM.readUChar(Storage::terrarium_hum_low_address);
    uint8_t hum_high = EEPROM.readUChar(Storage::terrarium_hum_high_address);
    EEPROM.end();
    return TerrariumSettings(temp_low, temp_high, hum_low, hum_high);
}
