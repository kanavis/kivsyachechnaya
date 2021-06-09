/* Terrarium settings header */
#pragma once
#include <string>
#include <cstdint>


class TerrariumSettings {
private:
    uint16_t _temp_low;
    uint16_t _temp_high;
    uint8_t _hum_low;
    uint8_t _hum_high;

public:
    TerrariumSettings(uint16_t temp_low, uint16_t temp_high, 
                      uint8_t hum_low, uint8_t hum_high);

    void validate();
    void setTempLow(uint16_t temp);
    uint16_t getTempLow();
    void setTempHigh(uint16_t temp);
    uint16_t getTempHigh();

    void setHumLow(uint8_t hum);
    uint8_t getHumLow();
    void setHumHigh(uint8_t hum);
    uint8_t getHumHigh();

    static TerrariumSettings* getDefault();
};
