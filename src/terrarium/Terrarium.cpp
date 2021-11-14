#include "terrarium/Terrarium.h"

#include "helpers/time_helpers.h"
#include "globals.h"

#include "kivsyachechnaya.h"


bool Terrarium::_startDelayPassed() {
    return timestamp() - _startTS < TERR_START_DELAY;
}

void Terrarium::_tickDevices() {
    Nebula_1->tick();
}

void Terrarium::_tickTerrarium() {
    /*
    * Turn on nebulizer if it's off and humidity
    * is lower than threshold and delay is over
    */
    if (
        _startDelayPassed() &&
        Nebula_1->isOff() && 
        Nebula_1->timeSinceStop() > TERR_HUMIDITY_DELAY
    ) {
        float hum = BME280_1->readHumidity();
        if (hum < terrariumSettings->getHumLow()) {
            __DEBUG(
                "Turning on nebulizer for %ds: hum=%.2f < %.2f", 
                TERR_NEBULA_TIME, hum, terrariumSettings->getHumLow()
            );
            Nebula_1->on_for(TERR_NEBULA_TIME);
        }
    }
}

void Terrarium::tick() {
    __DEBUG("AAAA");
    __DEBUG("ST %d", Nebula_1);
    __DEBUG("ST1 %d", Nebula_1->timeSinceStop());
    __DEBUG("BBBB");
    /*_tickDevices();
    _tickTerrarium();*/
}
