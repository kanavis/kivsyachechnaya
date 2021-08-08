#include <stdexcept>

#include "webserver/adapters.h"


/* BME280 */
bool BME280Adapter::hasReading(std::string reading) {
    if (!(
        reading == "temperature" ||
        reading == "pressure" ||
        reading == "altitude" ||
        reading == "humidity"
    )) return false;
    return true;
}

double BME280Adapter::getReading(std::string reading) {
    if (reading == "temperature") {
        __DEBUG("Get BME280 temp");
        return (*_device)->readTemperature();
    } else if (reading == "pressure") {
        __DEBUG("Get BME280 press");
        return (*_device)->readPressure();
    } else if (reading == "altitude") {
        __DEBUG("Get BME280 alt");
        return (*_device)->readAltitude(1013);
    } else if (reading == "humidity") {
        __DEBUG("Get BME280 hum");
        return (*_device)->readHumidity();
    } else {
        __DEBUG("No such reading %s", reading.c_str());
        throw std::runtime_error("No such reading");
    }
}
