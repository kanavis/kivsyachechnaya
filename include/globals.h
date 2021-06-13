/* Globals header */
#pragma once
#include "ESPAsyncWebServer.h"

#include "Networking.h"
#include "devices/DeviceBMP280I2C.h"
#include "settings_cls/SystemSettings.h"
#include "settings_cls/TerrariumSettings.h"


// Settings
extern SystemSettings* systemSettings;
extern TerrariumSettings* terrariumSettings;
extern Networking* networking;


// Webserver
extern AsyncWebServer* webServer;


/* Devices */

// BMP280-1
extern DeviceBMP280I2C* BMP280_1;
