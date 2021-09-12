/* Terrarium logic header */
#pragma once
#include <stdint.h>
#include "terrarium/device_helpers.h"


#define TERR_START_DELAY 60
#define TERR_HUMIDITY_DELAY 120
#define TERR_TEMP_DELAY 300
#define TERR_NEBULA_TIME 30


class Terrarium {
private:
    uint32_t _startTS;
    OnOffDevice * _devNebula1;

    void _tickDevices();
    void _tickTerrarium();
    bool _startDelayPassed();
public:
    Terrarium();
    void tick();
};
