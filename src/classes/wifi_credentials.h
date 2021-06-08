/* Wifi credentials header file */ 
#pragma once
#include <string>


class WifiCredentials {
private:
    std::string ssid;
    std::string password;

public:
    WifiCredentials(std::string ssid, std::string password);

    std::string getSSID();
    void setSSID(std::string ssid);
    std::string getPassword();
    void setPassword(std::string password);
};
