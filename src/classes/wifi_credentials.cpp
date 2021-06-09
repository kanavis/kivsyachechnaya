/* Wifi credentials */
#include <stdexcept>
#include <EEPROM.h>
#include "classes/constraints.h"
#include "classes/wifi_credentials.h"


WifiCredentials::WifiCredentials(std::string ssid, std::string password) {
    setSSID(ssid);
    setPassword(password);
}

void WifiCredentials::setSSID(std::string ssid) {
    Validation::ssid(ssid);
    _ssid = ssid;
}
std::string WifiCredentials::getSSID() { return _ssid; }

void WifiCredentials::setPassword(std::string password) {
    Validation::password(password);
    _password = password;
}
std::string WifiCredentials::getPassword() { return _password; }
