/* Globals header */
#pragma once
#include "ESPAsyncWebServer.h"

#include "devices/DeviceDHT.h"
#include "Networking.h"
#include "settings_cls/SystemSettings.h"
#include "settings_cls/TerrariumSettings.h"


// Settings
extern SystemSettings* systemSettings;
extern TerrariumSettings* terrariumSettings;
extern Networking* networking;


// Webserver
extern AsyncWebServer* webServer;


/* Devices */

// Hum & temp 1
extern DeviceDHT* DHT1;
