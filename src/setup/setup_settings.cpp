/* Setup settings */
#include "Arduino.h"
#include "setup_settings.h"
#include "cli/inputs.h"


void load_settings() {
    WifiCredentials wifi_credentials = Storage::loadWifiCredentials();
    TerrariumSettings terrarium_settings = Storage::loadTerrariumSettings();
    Settings settings = Settings(wifi_credentials, terrarium_settings);
    Settings::setGlobalettings(settings);
}

void init_settings() {
    Serial.println();
    Serial.println("*****************");
    Serial.println("* Initial setup *");
    Serial.println("*****************");
    Serial.println();

    WifiCredentials wifi_credentials = Inputs::wifi_credentials();
    Storage::saveWifiCredentials(wifi_credentials);

    TerrariumSettings terrarium_settings = TerrariumSettings::getDefault();
    Storage::saveTerrariumSettings(terrarium_settings);
    
    Settings settings = Settings(wifi_credentials, terrarium_settings);
    Settings::setGlobalettings(settings);

    Storage::setMagic();
}


void setup_settings() {
    if (Storage::hasMagic()) {
        load_settings();
    } else {
        init_settings();
    }
}
