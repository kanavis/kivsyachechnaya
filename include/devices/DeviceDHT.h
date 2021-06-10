/* DHT device class header */
#pragma once
#include <cstdint>
#include <string>

#include "DHT.h"


class DeviceDHT: public DHT {
private:
    uint8_t _id;
    uint8_t _retry_count;
public:
    DeviceDHT(uint8_t id, uint8_t pin, uint8_t type, uint8_t retry_count = 3, uint8_t count = 6)
    :DHT(pin, type, count), _id(id), _retry_count(retry_count) {};

    float readHumidityWithRetries();
    float readTemperatureWithRetries();
};
