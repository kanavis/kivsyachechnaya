#include "terrarium/Terrarium.h"

#include "helpers/time_helpers.h"
#include "globals.h"


Terrarium::Terrarium() {
    _devNebula1 = new OnOffDevice("nebulizer_1", Nebula_1);
    _startTS = timestamp();
}

bool Terrarium::_startDelayPassed() {
    return timestamp() - _startTS < TERR_START_DELAY;
}

void Terrarium::_tickDevices() {
    _devNebula1->tick();
}

void Terrarium::_tickTerrarium() {
    /*
    * Turn on nebulizer if it's off and humidity
    * is lower than threshold and delay is over
    */
    if (
        _startDelayPassed() &&
        _devNebula1->isOff() && 
        _devNebula1->timeSinceStop() > TERR_HUMIDITY_DELAY
    ) {
        float hum = BME280_1->readHumidity();
        if (hum < terrariumSettings->getHumLow()) {
            __DEBUG(
                "Turning on nebulizer for %ds: hum=%.2f < %.2f", 
                TERR_NEBULA_TIME, hum, terrariumSettings->getHumLow()
            );
            _devNebula1->on_for(TERR_NEBULA_TIME);
        }
    }
}

void Terrarium::tick() {
    _tickDevices();
    _tickTerrarium();
}
