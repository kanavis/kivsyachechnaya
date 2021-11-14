/* BME280 device */
#include "kivsyachechnaya.h"

#include "devices/DeviceBME280I2C.h"


float DeviceBME280I2C::readPressureWithRetries() {
    float pressure;
    unsigned char n_try = 0;
    do {
        pressure = readPressure();
        if (NAN == pressure) {__DEBUG("Got NULL pressure from DHT %d.", _id);}
        n_try++;
    } while (NAN == pressure && n_try < _retry_count);
    
    if (NAN == pressure) {
        __DEBUG("Got NULL pressure from DHT %d on %d tries. Give up", _id, n_try);
    } else {
        __DEBUG("Got pressure %.2f from DHT %d", pressure, _id);
    }

    return pressure;
}


float DeviceBME280I2C::readTemperatureWithRetries() {
    float temperature;
    unsigned char n_try = 0;
    do {
        temperature = readTemperature();
        if (NAN == temperature) {__DEBUG("Got NULL temperature from DHT %d.", _id);}
        n_try++;
    } while (NAN == temperature && n_try < _retry_count);
    
    if (NAN == temperature) {
        __DEBUG("Got NULL temperature from DHT %d on %d tries. Give up", _id, n_try);
    } else {
        __DEBUG("Got temperature %.2f from DHT %d", temperature, _id);
    }

    return temperature;
}
