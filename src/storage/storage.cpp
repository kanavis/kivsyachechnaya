/* Storage implementation */
#include "EEPROM.h"
#include "storage.h"
#include "classes/wifi.h"


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
void Storage::saveWifiCredentials(WifiCredentials credentials) {
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
