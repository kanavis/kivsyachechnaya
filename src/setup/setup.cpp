/* Setup process */
#include <stdlib.h>
#include <time.h>

#include "kivsyachechnaya.h"
#include "setup/setup_devices.h"
#include "setup/setup_fs.h"
#include "setup/setup_networking.h"
#include "setup/setup_settings.h"
#include "setup/setup_webserver.h"

#include "setup/setup.h"


void setup_timezone() {
    __DEBUG("Setup timezone to " TIMEZONE);
    setenv("TZ", TIMEZONE, 1);
    tzset();
}


void _setup() {
    setup_settings();
    setup_timezone();
    setup_networking();
    setup_devices();
    setup_fs();
    setup_webserver();
    __DEBUG("Setup complete");
    __DEBUG("Memory status after setup: heap_size %d; heap_free %d", ESP.getHeapSize(), ESP.getFreeHeap());
}
