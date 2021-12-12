/* CLI inputs */
#include "Arduino.h"

#include "helpers/time_helpers.h"
#include "settings_cls/constraints.h"

#include "CLI/inputs.h"


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


std::string user_input_str(const char * request, unsigned long min_length = 0, unsigned long max_length = 0, bool echo = true) {
    std::string read;
    for (;;) {
        Serial.print(request);
        read = __user_str_input(echo);
        if (max_length && read.length() > max_length) {
            Serial.print("Value must not be longer than ");
            Serial.print(max_length);
            Serial.println(" chars.");
        } else if (min_length && read.length() < min_length) {
            if (read.length() > 0) {
                Serial.print("Value must not be shorter than ");
                Serial.print(min_length);
                Serial.println(" chars.");
            }
        } else {
            return read;
        }
    }
}


bool Inputs::expect_enter(std::string message, uint timeout) {
    int64_t time_start = utimestamp();
    int32_t last_time_left = -1;
    char c;
    for (;;) {
        int32_t time_passed = (utimestamp() - time_start) / 1000000;
        int32_t time_left = timeout - time_passed;
        if (last_time_left != time_left) {
            last_time_left = time_left;
            Serial.print("\r");
            Serial.print(message.c_str());
            Serial.print(" ");
            Serial.print(time_left < 0 ? 0 : time_left);
        }
        if (time_left <= 0) {
            Serial.println();
            return false;
        }
        Serial.readBytes(&c, 1);
        if (c == '\n') {
            Serial.println();
            return true;
        } else if (c == ' ') {
            return false;
        }
    }
}


SystemSettings* Inputs::system_settings() {
    std::string wifi_ssid = user_input_str("Wi-fi SSID: ", WIFI_MIN_SSID_LENGTH, WIFI_MAX_SSID_LENGTH);
    std::string wifi_password = user_input_str("Wi-fi password: ", WIFI_MIN_PASSWORD_LENGTH, WIFI_MAX_PASSWORD_LENGTH, false);
    return new SystemSettings(wifi_ssid, wifi_password);
}
