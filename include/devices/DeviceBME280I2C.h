/* BME280 device header */
#pragma once
#include <Adafruit_BME280.h>


class DeviceBME280I2C: public Adafruit_BME280 {
private:
    unsigned char _id;
    unsigned char _retry_count;

public:
    DeviceBME280I2C(unsigned char id, unsigned char retry_count)
    :Adafruit_BME280(), _id(id), _retry_count(retry_count) {};

    float readPressureWithRetries();
    float readTemperatureWithRetries();
};
