/* Setup settings */
#include "kivsyachechnaya.h"
#include "setup/setup_settings.h"
#include "CLI/CLI.h"


void load_settings() {
    Serial.println();
    Serial.println("*******************");
    Serial.println("* KIVSYACHECHNAYA *");
    Serial.println("*     Loading     *");
    Serial.println("*******************");
    Serial.println();

    WifiCredentials* wifi_credentials;
    if (Inputs::expect_enter("If you want to change wifi settings, press enter...")) {
        __DEBUG("Read wifi credentials");
        wifi_credentials = Inputs::wifi_credentials();
        Storage::saveWifiCredentials(wifi_credentials);
    } else {
        __DEBUG("Load wifi credentials");
        wifi_credentials = Storage::loadWifiCredentials();
    }

    __DEBUG("Load terrarium setting");
    TerrariumSettings* terrarium_settings = Storage::loadTerrariumSettings();
    __DEBUG("Make settings global");
    Settings::setGlobalSettings(new Settings(*wifi_credentials, *terrarium_settings));
    __DEBUG("Settings loading complete");
}

void init_settings() {
    Serial.println();
    Serial.println("*******************");
    Serial.println("* KIVSYACHECHNAYA *");
    Serial.println("*  Initial setup  *");
    Serial.println("*******************");
    Serial.println();

    __DEBUG("Read wifi credentials");
    WifiCredentials* wifi_credentials = Inputs::wifi_credentials();
    Storage::saveWifiCredentials(wifi_credentials);

    __DEBUG("Initialize terrarium settings");
    TerrariumSettings* terrarium_settings = TerrariumSettings::getDefault();
    Storage::saveTerrariumSettings(terrarium_settings);
    
    __DEBUG("Initialize settings", "Aaa");
    Settings::setGlobalSettings(new Settings(*wifi_credentials, *terrarium_settings));

    __DEBUG("Set magic");
    Storage::setMagic();
    __DEBUG("Settings init complete");
}

void print_settings() {
    Serial.println("Starting with settings:");
    Serial.print("  WIFI SSID: ");
    Serial.println(Settings::getSettings().getWifiCredentials().getSSID().c_str());
    Serial.print("  Temp:       ");
    Serial.print(Settings::getSettings().getTerrariumSettings().getTempLow());
    Serial.print(" - ");
    Serial.println(Settings::getSettings().getTerrariumSettings().getTempHigh());
    Serial.print("  Humidity:   ");
    Serial.print(Settings::getSettings().getTerrariumSettings().getHumLow());
    Serial.print(" - ");
    Serial.println(Settings::getSettings().getTerrariumSettings().getHumHigh());
}


void setup_settings() {
    if (Storage::hasMagic()) {
        #ifdef SETTINGS_RESET
        init_settings();
        #else
        load_settings();
        #endif
    } else {
        init_settings();
    }
    delay(100);
    print_settings();
}
