/* CLI inputs */
#include "inputs.h"
#include "classes/constraints.h"
#include "Arduino.h"


std::string __user_str_input(bool echo) {
    char c;
    std::string read;
    for (;;) {
        if (Serial.readBytes(&c, 1)) {
            if (c == '\n') {
                break;
            } else if (c != '\r') {
                if (echo) Serial.write(&c, 1);
                if (c == 8) {
                    if (!read.empty()) read.resize(read.size() - 1);
                } else {
                    read.push_back(c);
                }
            }
        }
    }
    Serial.println();
    return read;
}


std::string user_input_str(const char * request, unsigned long max_length = 0, bool echo = true) {
    Serial.print(request);
    std::string read;
    for (;;) {
        read = __user_str_input(echo);
        if (max_length && read.length() > max_length) {
            Serial.print("Value must be shorter than ");
            Serial.print(max_length);
            Serial.print(" chars.");
        } else {
            return read;
        }
    }
}


WifiCredentials Inputs::wifi_credentials() {
    std::string ssid = user_input_str("Wi-fi SSID: ", WIFI_MAX_SSID_LENGTH);
    std::string password = user_input_str("Wi-fi password: ", WIFI_MAX_PASSWORD_LENGTH, false);
    return WifiCredentials(ssid, password);
}
