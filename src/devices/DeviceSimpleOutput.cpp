#include <Arduino.h>

#include "devices/DeviceSimpleOutput.h"


DeviceSimpleOutput::DeviceSimpleOutput(uint8_t pin): _pin(pin) {
    pinMode(_pin, OUTPUT);
}

void DeviceSimpleOutput::enable() {
    digitalWrite(_pin, HIGH);
}

void DeviceSimpleOutput::disable() {
    digitalWrite(_pin, LOW);
}
