/* Wifi storage */
#include <stdexcept>
#include <EEPROM.h>
#include "constraints.h"
#include "helpers/string.h"
#include "wifi.h"


WifiCredentials::WifiCredentials(std::string ssid, std::string password) {
    this->setSSID(ssid);
    this->setPassword(password);
}

void WifiCredentials::setSSID(std::string ssid) {
    if (ssid.length() > WIFI_MAX_SSID_LENGTH) {
        throw std::runtime_error(string_format("Wifi SSID cannot be longer than %d", WIFI_MAX_SSID_LENGTH));
    }
    this->ssid = ssid;
}
std::string WifiCredentials::getSSID() { return this->ssid; }

void WifiCredentials::setPassword(std::string password) {
    if (password.length() > WIFI_MAX_PASSWORD_LENGTH) {
        throw std::runtime_error(string_format("Wifi password cannot be longer than %d", WIFI_MAX_PASSWORD_LENGTH));
    }
    this->password = password;
}
std::string WifiCredentials::getPassword() { return this->password; }
