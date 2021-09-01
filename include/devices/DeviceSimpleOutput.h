/* Simple output device */
#pragma once


class DeviceSimpleOutput {
private:
    uint8_t _pin;

public:
    DeviceSimpleOutput(uint8_t pin);
    void enable();
    void disable();
};
