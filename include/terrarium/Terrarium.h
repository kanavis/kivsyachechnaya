/* Terrarium logic header */
#pragma once
#include <stdint.h>

#include "devices/DeviceSimpleOutput.h"
#include "helpers/time_helpers.h"

#include "kivsyachechnaya.h"


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
    Terrarium(OnOffDevice * devNebula1):
      _devNebula1(devNebula1) {
        __DEBUG("Init nebula1");
        _startTS = timestamp();
      };
    void tick();
};
