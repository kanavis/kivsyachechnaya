/* Setup devices */
#include <stdexcept>
#include "Wire.h"

#include "device_config.h"
#include "devices/DeviceBMP280I2C.h"
#include "globals.h"
#include "kivsyachechnaya.h"

#include "setup/setup_devices.h"


DeviceBMP280I2C* BMP280_1;


void setup_devices() {
    __DEBUG("Setup devices");
    __DEBUG("Setup I2C");
    Wire.begin(I2C_SDA, I2C_SCL);
    __DEBUG("Setup I2C complete");

    __DEBUG("Setup BMP280 1");
    BMP280_1 = new DeviceBMP280I2C(1, BMP280_RETRIES);
    if (!BMP280_1->begin()) {
        throw std::runtime_error("Couldn't initialize BMP280-1");
    }
    BMP280_1->setSampling(
        Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
        Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
        Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
        Adafruit_BMP280::FILTER_X16,      /* Filtering. */
        Adafruit_BMP280::STANDBY_MS_500   /* Standby time. */
    );
    __DEBUG("Setup BMP280 1 complete");
    __DEBUG("Device setup complete");
}
