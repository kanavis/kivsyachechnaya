/* System settings */
#include <EEPROM.h>
#include <stdexcept>

#include "settings_cls/constraints.h"
#include "settings_cls/SystemSettings.h"


SystemSettings::SystemSettings(std::string wifi_ssid, std::string wifi_password) {
    setWifiSSID(wifi_ssid);
    setWifiPassword(wifi_password);
}

void SystemSettings::setWifiSSID(std::string ssid) {
    Validation::ssid(ssid);
    _wifiSSID = ssid;
}
std::string SystemSettings::getWifiSSID() { return _wifiSSID; }

void SystemSettings::setWifiPassword(std::string password) {
    Validation::password(password);
    _wifiPassword = password;
}
std::string SystemSettings::getWifiPassword() { return _wifiPassword; }
