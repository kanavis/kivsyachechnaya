/* BMP280 device header */
#pragma once
#include <Adafruit_BMP280.h>


class DeviceBMP280I2C: public Adafruit_BMP280 {
private:
    unsigned char _id;
    unsigned char _retry_count;

public:
    DeviceBMP280I2C(unsigned char id, unsigned char retry_count)
    :Adafruit_BMP280(), _id(id), _retry_count(retry_count) {};

    float readPressureWithRetries();
    float readTemperatureWithRetries();
};
