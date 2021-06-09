/* Data constraints validation */
#include <stdexcept>
#include <string> 

#include "helpers/string_helpers.h"
#include "settings_cls/constraints.h"


ValidationError::ValidationError(std::string error) { _error = error; }
char const* ValidationError::what() { return _error.c_str(); }


void Validation::ssid(std::string ssid) {
    if (ssid.length() > WIFI_MAX_SSID_LENGTH) {
        throw ValidationError("Wifi SSID cannot be longer than " + to_string(WIFI_MAX_SSID_LENGTH));
    }
}

void Validation::password(std::string password) {
    if (password.length() > WIFI_MAX_PASSWORD_LENGTH) {
        throw ValidationError("Wifi password cannot be longer than " + to_string(WIFI_MAX_PASSWORD_LENGTH));
    }
}

void Validation::temp(int temp) {
    if (temp < TEMP_MIN) {
        throw ValidationError("Temperature cannot be less than " + to_string(TEMP_MIN));
    }
    if (temp > TEMP_MAX) {
        throw ValidationError("Temperature cannot be more than " + to_string(TEMP_MAX));
    }
}

void Validation::hum(int hum) {
    if (hum < HUM_MIN) {
        throw ValidationError("Humidity cannot be less than " + to_string(HUM_MIN));
    }
    if (hum > HUM_MAX) {
        throw ValidationError("Humidity cannot be more than " + to_string(HUM_MAX));
    }
}
