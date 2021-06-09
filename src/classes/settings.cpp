/* Settings */
#include "classes/settings.h"


Settings* Settings::global_settings = NULL;
bool Settings::_initialized = false;


WifiCredentials& Settings::getWifiCredentials() {
    return _wifi_credentials;
}

TerrariumSettings& Settings::getTerrariumSettings() {
    return _terrarium_settings;
}


Settings& Settings::getSettings() {
    if (!Settings::_initialized) {
        throw std::runtime_error("Settings referenced before init");
    }
    return *Settings::global_settings;
}

void Settings::setGlobalSettings(Settings* settings) {
    Settings::global_settings = settings;
    Settings::_initialized = true;
}
