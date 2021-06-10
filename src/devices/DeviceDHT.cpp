/* DHT device class */
#include "kivsyachechnaya.h"

#include "devices/DeviceDHT.h"


float DeviceDHT::readHumidityWithRetries() {
    float humidity;
    uint n_try = 0;
    do {
        humidity = readHumidity();
        if (NAN == humidity) {__DEBUG("Got NULL humidity from DHT %d.", _id);}
        n_try++;
    } while (NAN == humidity && n_try < _retry_count);
    
    if (NAN == humidity) {
        __DEBUG("Got NULL humidity from DHT %d on %d tries. Give up", _id, n_try);
    } else {
        __DEBUG("Got humidity %.2f from DHT %d", humidity, _id);
    }

    return humidity;
}

float DeviceDHT::readTemperatureWithRetries() {
    float temperature;
    uint n_try = 0;
    do {
        temperature = readTemperature();
        if (NAN == temperature) {__DEBUG("Got NULL temperature from DHT %d.", _id);}
        n_try++;
    } while (NAN == temperature && n_try < _retry_count);
    
    if (NAN == temperature) {
        __DEBUG("Got NULL temperature from DHT %d on %d tries. Give up", _id, n_try);
    } else {
        __DEBUG("GOT temperature %.2f from DHT %d", temperature, _id);
    }

    return temperature;
}
