/* Settings */
#include "settings.h"


bool Settings::settings_initialized = false;
Settings* Settings::global_settings = NULL;


WifiCredentials& Settings::getWifiCredentials() {
    return _wifi_credentials;
}

TerrariumSettings& Settings::getTerrariumSettings() {
    return _terrarium_settings;
}


Settings& Settings::getSettings() {
    if (!Settings::settings_initialized) {
        throw std::runtime_error("Settings referenced before init");
    }
    return *Settings::global_settings;
}

void Settings::setGlobalettings(Settings& settings) {
    Settings::global_settings = &settings;
    Settings::settings_initialized = true;
}
