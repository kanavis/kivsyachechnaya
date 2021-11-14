/* Simple output device */
#pragma once

#include <string>

#define STATE_OFF 0;
#define STATE_ON 1;


class DeviceSimpleOutput {
private:
    uint8_t _pin;

public:
    DeviceSimpleOutput(uint8_t pin);
    void enable();
    void disable();
};


class OnOffDevice: public DeviceSimpleOutput {
private:
    std::string _name;

    unsigned char state;
    uint32_t started_at;
    uint32_t works_until;
    uint32_t stopped_at;
public:
    OnOffDevice(uint8_t pin, std::string name):
    DeviceSimpleOutput(pin), _name(name)  { stopped_at = 0; started_at = 0; works_until = 0; state = STATE_OFF; };
    void _on();
    void _off();

    void on();
    void off();

    void on_for(uint16_t duration);
    uint32_t timeSinceStop();

    bool isOn();
    bool isOff();

    void tick();
};
