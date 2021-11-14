/* Globals header */
#pragma once
#include "ESPAsyncWebServer.h"

#include "Networking.h"
#include "terrarium/Terrarium.h"
#include "devices/DeviceBME280I2C.h"
#include "devices/DeviceSimpleOutput.h"
#include "settings_cls/SystemSettings.h"
#include "settings_cls/TerrariumSettings.h"


// Settings
extern SystemSettings* systemSettings;
extern TerrariumSettings* terrariumSettings;


/* Devices */
// BMP280-1
extern DeviceBME280I2C* BME280_1;

// Nebulizer 1
extern OnOffDevice* Nebula_1;


// Global obects
extern Networking* networking;
extern Terrarium* terrarium;

// Webserver
extern AsyncWebServer* webServer;

