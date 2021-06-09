/* Wifi setup */

#include <WiFi.h>
#include "classes/settings.h"
#include "setup/setup_wifi.h"


void setup_wifi() {
    WifiCredentials credentials = Settings::getSettings().getWifiCredentials();
    WiFi.mode(WIFI_STA);
    
    WiFi.begin(credentials.getSSID().c_str(), credentials.getPassword().c_str());
    uint8_t res = WiFi.waitForConnectResult();
    if (res != WL_CONNECTED) {
        Serial.print("WiFi connect failed with status ");
        Serial.println(res);
        return;
    }
    Serial.print("Wifi connected. SSID=");
    Serial.print(credentials.getSSID().c_str());
    Serial.print(" IP=");
    Serial.println(WiFi.localIP());
}
