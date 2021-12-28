/* Setup devices */
#include <stdexcept>
#include "Wire.h"

#include "device_config.h"
#include "devices/DeviceBME280I2C.h"
#include "globals.h"

#include "kivsyachechnaya.h"

#include "setup/setup_devices.h"


DeviceBME280I2C *BME280_1;
OnOffDevice *Nebula_1;
OnOffDevice *Heater_1;


void setup_devices() {
    __DEBUG("Setup devices");
    __DEBUG("Setup I2C");
    Wire.begin(I2C_SDA, I2C_SCL);
    __DEBUG("Setup I2C complete");

    
    __DEBUG("Setup Nebulizer 1");
    Nebula_1 = new OnOffDevice(NEBULA1_PIN, "Nebula1");
    __DEBUG("Nebulizer 1 setup complete");

    __DEBUG("Setup Heater 1");
    Heater_1 = new OnOffDevice(HEATER1_PIN, "Heater1");
    Heater_1->on();
    __DEBUG("Heater 1 setup complete");

    return;

    __DEBUG("Setup BME280 1");
    BME280_1 = new DeviceBME280I2C(1, BME280_RETRIES);
    if (!BME280_1->begin(0x76, &Wire)) {
        throw std::runtime_error("Couldn't initialize BME280-1");
    }
    BME280_1->setSampling(
        Adafruit_BME280::MODE_NORMAL,     /* Operating Mode. */
        Adafruit_BME280::SAMPLING_X2,     /* Temp. oversampling */
        Adafruit_BME280::SAMPLING_X16,    /* Pressure oversampling */
        Adafruit_BME280::SAMPLING_X16,    /* Humidity oversampling */
        Adafruit_BME280::FILTER_X16,      /* Filtering. */
        Adafruit_BME280::STANDBY_MS_500   /* Standby time. */
    );
    __DEBUG("Setup BME280 1 complete");
    
    __DEBUG("Device setup complete");
}
