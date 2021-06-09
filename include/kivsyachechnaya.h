/* Main kiv header */
#pragma once

#include <Arduino.h>
#include "esp_log.h"


#define TIMEZONE "MSK-03"
#define NTP_SERVER "pool.ntp.org"

// #define SETTINGS_RESET

#define MAIN_LOOP_DELAY 10000

#define HTTP_PORT 80

#ifdef ENABLE_DEBUG
    #define __DEBUG(FMT, ...) log_printf("__DEBUG: " FMT "\n", ##__VA_ARGS__)
#else
    #define __DEBUG(FMT, ...)
#endif
