/* System settings header file */ 
#pragma once

#include <string>


class SystemSettings {
private:
    std::string _wifiSSID;
    std::string _wifiPassword;

public:
    SystemSettings(std::string wifi_ssid, std::string wifi_password);

    std::string getWifiSSID();
    void setWifiSSID(std::string ssid);
    std::string getWifiPassword();
    void setWifiPassword(std::string password);
};
