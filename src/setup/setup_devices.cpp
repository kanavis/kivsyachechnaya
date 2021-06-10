/* Setup devices */
#include "device_config.h"
#include "devices/DeviceDHT.h"
#include "globals.h"
#include "kivsyachechnaya.h"

#include "setup/setup_devices.h"


DeviceDHT* DHT1;


void setup_devices() {
    __DEBUG("Setup devices");
    __DEBUG("Setup DHT1");
    DHT1 = new DeviceDHT(1, HUMTEMP1_PIN, HUMTEMP1_DHTTYPE, HUMTEMP1_RETRIES);
    DHT1->begin();
    __DEBUG("Device setup complete");
}
