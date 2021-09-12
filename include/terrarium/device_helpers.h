/* Device helpers */
#pragma once
#include <stdint.h>
#include <string>

#include "devices/DeviceSimpleOutput.h"


#define STATE_OFF 0;
#define STATE_ON 1;


class OnOffDevice {
private:
    DeviceSimpleOutput * _device;
    std::string _name;

    unsigned char state;
    uint32_t started_at;
    uint32_t works_until;
    uint32_t stopped_at;
public:
    OnOffDevice(std::string name, DeviceSimpleOutput * device):
    _device(device), _name(name)  { stopped_at = 0; started_at = 0; works_until = 0; state = STATE_OFF; };
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
