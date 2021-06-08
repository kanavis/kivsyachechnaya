/* Terrarium settings */
#include "terrarium_settings.h"
#include "constraints.h"


TerrariumSettings::TerrariumSettings(uint16_t temp_low, uint16_t temp_high, 
                                     uint8_t hum_low, uint8_t hum_high) 
{
    this->setTempLow(temp_low);
    this->setTempHigh(temp_high);
    this->setHumLow(hum_low);
    this->setHumHigh(hum_high);
}


TerrariumSettings TerrariumSettings::getDefault() {
    return TerrariumSettings(21, 23, 75, 85);
}

void TerrariumSettings::validate() {
    if (_temp_low >= _temp_high) {
        throw ValidationError("Low temperature must be lower than high temperature");
    }
    if (_hum_low >= _hum_high) {
        throw ValidationError("Low humidity must be lower than high humidity");
    }
}

void TerrariumSettings::setTempLow(uint16_t temp) {
    Validation::temp(temp);
    _temp_low = temp;
}
uint16_t TerrariumSettings::getTempLow() { validate(); return _temp_low; }

void TerrariumSettings::setTempHigh(uint16_t temp) {
    Validation::temp(temp);
    _temp_low = temp;
}
uint16_t TerrariumSettings::getTempHigh() { validate(); return _temp_high; }

void TerrariumSettings::setHumLow(uint8_t hum) {
    Validation::hum(hum);
    _hum_low = hum;
}
uint8_t TerrariumSettings::getHumLow() { validate(); return _hum_low; }

void TerrariumSettings::setHumHigh(uint8_t hum) {
    Validation::hum(hum);
    _hum_high = hum;
}
uint8_t TerrariumSettings::getHumHigh() { validate(); return _hum_high; }
