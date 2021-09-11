/* Setup settings */
#include "CLI/CLI.h"
#include "globals.h"
#include "kivsyachechnaya.h"
#include "settings_cls/SystemSettings.h"
#include "Storage.h"

#include "setup/setup_settings.h"


SystemSettings* systemSettings;
TerrariumSettings* terrariumSettings;


void load_settings() {
    Serial.println();
    Serial.println("*******************");
    Serial.println("* KIVSYACHECHNAYA *");
    Serial.println("*     Loading     *");
    Serial.println("*******************");
    Serial.println();

    if (Inputs::expect_enter("If you want to change wifi settings, press enter...")) {
        __DEBUG("Read wifi credentials");
        systemSettings = Inputs::system_settings();
        Storage::saveSystemSettings();
    } else {
        __DEBUG("Load wifi credentials");
        Storage::loadSystemSettings();
    }

    __DEBUG("Load terrarium setting");
    Storage::loadTerrariumSettings();
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
    systemSettings = Inputs::system_settings();
    Storage::saveSystemSettings();

    __DEBUG("Initialize terrarium settings");
    terrariumSettings = TerrariumSettings::getDefault();
    Storage::saveTerrariumSettings();

    __DEBUG("Set magic");
    Storage::setMagic();
    __DEBUG("Settings init complete");
}

void print_settings() {
    Serial.println("Starting with settings:");
    Serial.print("  WIFI SSID: ");
    Serial.println(systemSettings->getWifiSSID().c_str());
    Serial.print("  Temp:       ");
    Serial.print(terrariumSettings->getTempLow());
    Serial.print(" - ");
    Serial.println(terrariumSettings->getTempHigh());
    Serial.print("  Humidity:   ");
    Serial.print(terrariumSettings->getHumLow());
    Serial.print(" - ");
    Serial.println(terrariumSettings->getHumHigh());
}


void setup_settings() {
    if (Storage::hasMagic()) {
        #ifdef SETTINGS_RESET
        __DEBUG("defined SETTINGS_RESET");
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
