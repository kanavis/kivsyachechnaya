/* Wifi credentials */
#include <stdexcept>
#include <EEPROM.h>
#include "constraints.h"
#include "helpers/string.h"
#include "wifi_credentials.h"


WifiCredentials::WifiCredentials(std::string ssid, std::string password) {
    this->setSSID(ssid);
    this->setPassword(password);
}

void WifiCredentials::setSSID(std::string ssid) {
    Validation::ssid(ssid);
    this->ssid = ssid;
}
std::string WifiCredentials::getSSID() { return ssid; }

void WifiCredentials::setPassword(std::string password) {
    Validation::password(password);
    this->password = password;
}
std::string WifiCredentials::getPassword() { return password; }
