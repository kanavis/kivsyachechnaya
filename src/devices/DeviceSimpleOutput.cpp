#include <Arduino.h>

#include "devices/DeviceSimpleOutput.h"
#include "helpers/time_helpers.h"

#include "kivsyachechnaya.h"


DeviceSimpleOutput::DeviceSimpleOutput(uint8_t pin): _pin(pin) {
    pinMode(_pin, OUTPUT);
}

void DeviceSimpleOutput::enable() {
    digitalWrite(_pin, HIGH);
}

void DeviceSimpleOutput::disable() {
    digitalWrite(_pin, LOW);
}


void OnOffDevice::_on() {
    enable();
    state = STATE_ON;
    started_at = timestamp();
}

void OnOffDevice::_off() {
    disable();
    state = STATE_OFF;
    stopped_at = timestamp();
    works_until = 0;
}

void OnOffDevice::on() {
    __DEBUG("ENABLE %s", _name);
    _on();
    works_until = 0;
}

void OnOffDevice::off() {
    __DEBUG("DISABLE %s", _name);
    _off();
}

void OnOffDevice::on_for(uint16_t duration) {
    __DEBUG("ENABLE %s for %ds", _name, duration);
    _on();
    works_until = timestamp() + duration;
}

uint32_t OnOffDevice::timeSinceStop() {
    return timestamp() - stopped_at;
}

bool OnOffDevice::isOn() {
    return state == STATE_ON;
}

bool OnOffDevice::isOff() {
    return state == STATE_ON;
}

void OnOffDevice::tick() {
    int32_t ts = timestamp();
    if (works_until && ts >= works_until) {
        __DEBUG("DISABLE %s: works_until=%d, ts=%d", _name, works_until, ts);
        _off();
    }
}
