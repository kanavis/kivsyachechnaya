/* Networking services */
#include <NTPClient.h>
#include <AsyncUDP.h>
#include <sys/time.h>
#include <WiFi.h>

#include "globals.h"
#include "helpers/time_helpers.h"
#include "kivsyachechnaya.h"
#include "time.h"

#include "Networking.h"


WiFiUDP ntpUDP;
AsyncUDP udp;


Networking::Networking() {
    _ntpClient = new NTPClient(ntpUDP, NTP_SERVER, 0);    // Ntp client holds UTC time
    _NTPLastUpdateTs = 0;
    _BeaconLastSendTs = 0;
}


void Networking::_wifiConnect() {
    WiFi.disconnect();;
    WiFi.mode(WIFI_STA);

    WiFi.begin(systemSettings->getWifiSSID().c_str(), systemSettings->getWifiPassword().c_str());
    uint8_t res = WiFi.waitForConnectResult();
    if (res != WL_CONNECTED) {
        Serial.print("WiFi connect failed with status ");
        Serial.println(res);
        return;
    }
    Serial.print("Wifi connected. SSID=");
    Serial.print(systemSettings->getWifiSSID().c_str());
    Serial.print(" IP=");
    Serial.println(WiFi.localIP());
}


void Networking::_NTPSetSystemTime() {
    struct timeval now = {(time_t)_ntpClient->getEpochTime(), 0};
    Serial.print("Updated localtime ");
    Serial.print(strftime_str("%Y-%m-%d %H:%M:%S %z").c_str());
    settimeofday(&now, NULL);
    Serial.print(" -> ");
    Serial.print(strftime_str("%Y-%m-%d %H:%M:%S %z").c_str());
    Serial.print(" (");
    Serial.print(now.tv_sec);
    Serial.println(")");
}


void Networking::_NTPUpdate() {
    if (WiFi.isConnected() && _ntpClient->forceUpdate()) {
        Serial.println("NTP update complete");
        _NTPSetSystemTime();
        _NTPLastUpdateTs = timestamp();
    } else {
        Serial.println("NTP update failed");
    }
}


void Networking::_BeaconSend() {
    __DEBUG("Sending network beacon");
    udp.broadcastTo(BEACON_PAYLOAD, BEACON_PORT);
    _BeaconLastSendTs = timestamp();
}


void Networking::start() {
    Serial.println("Connecting to WiFi");
    _wifiConnect();
    Serial.println("Updating time via NTP");
    _NTPUpdate();
}


void Networking::tick() {
    if (!WiFi.isConnected()) {
        Serial.println("Lost WiFi connection, retrying");
        _wifiConnect();
    }
    int32_t ts = timestamp();
    if (ts - _NTPLastUpdateTs > NTP_UPDATE_INTERVAL_SEC) {
        _NTPUpdate();
    }
    if (ts - _BeaconLastSendTs > BEACON_INTERVAL_SEC) {
        _BeaconSend();
    }
}