/* Data constraints validation */
#include <stdexcept>
#include <string> 
#include "helpers/string.h"
#include "constraints.h"

ValidationError::ValidationError(std::string error) { _error = error; }
char const* ValidationError::what() { return _error.c_str(); }


void Validation::ssid(std::string ssid) {
    if (ssid.length() > WIFI_MAX_SSID_LENGTH) {
        throw ValidationError(string_format("Wifi SSID cannot be longer than %d", WIFI_MAX_SSID_LENGTH));
    }
}

void Validation::password(std::string password) {
    if (password.length() > WIFI_MAX_PASSWORD_LENGTH) {
        throw ValidationError(string_format("Wifi password cannot be longer than %d", WIFI_MAX_PASSWORD_LENGTH));
    }
}

void Validation::temp(int temp) {
    if (temp < TEMP_MIN) {
        throw ValidationError(string_format("Temperature cannot be less than %d", TEMP_MIN));
    }
    if (temp > TEMP_MAX) {
        throw ValidationError(string_format("Temperature cannot be more than %d", TEMP_MAX));
    }
}

void Validation::hum(int hum) {
    if (hum < HUM_MIN) {
        throw ValidationError(string_format("Humidity cannot be less than %d", HUM_MIN));
    }
    if (hum > HUM_MAX) {
        throw ValidationError(string_format("Humidity cannot be more than %d", HUM_MAX));
    }
}
