#pragma once
#include <string>

#include "devices/DeviceBME280I2C.h"

#include "kivsyachechnaya.h"


class ISensorAdapter {
public:
    virtual double getReading(std::string reading) = 0;
    virtual bool hasReading(std::string reading) = 0;
};


class BME280Adapter: public ISensorAdapter {
private:
    DeviceBME280I2C ** _device;
public:
    BME280Adapter(DeviceBME280I2C ** device):
    _device(device) {};

    double getReading(std::string reading);
    bool hasReading(std::string reading);
};
