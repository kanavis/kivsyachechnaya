/* Networking services header */
#pragma once

#include <cstdint>
#include <NTPClient.h>

#include "kivsyachechnaya.h"


// NTP
#define NTP_SERVER "pool.ntp.org"
#define UTC_OFFSET 3 * 3600
#define NTP_UPDATE_INTERVAL_SEC 3600


class Networking {
private:
    NTPClient* _ntpClient;
    int32_t _NTPLastUpdateTs;

    void _wifiConnect();
    void _NTPUpdate();
    void _NTPSetSystemTime();

public:
    Networking();

    void start();
    void tick();
};
