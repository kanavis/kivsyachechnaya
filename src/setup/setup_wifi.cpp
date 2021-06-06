/* Wifi setup */

#include <WiFi.h>
#include "setup_wifi.h"


void setup_wifi() {
    WiFi.mode(WIFI_STA);
    // WiFi.begin(ssid, password);
    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.printf("WiFi Failed!\n");
        return;
    }
}
