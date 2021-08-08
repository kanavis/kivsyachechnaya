/* Simple output device */
#pragma once
#include <Adafruit_BMP280.h>


class DeviceSimpleOutput: public Adafruit_BMP280 {
private:
    uint8_t _pin;

public:
    DeviceSimpleOutput(uint8_t pin);
    void enable();
    void disable();
};
