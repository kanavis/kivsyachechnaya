#include <Arduino.h>
#include "esp_log.h"

#define GMT_OFFSET_SEC 3600 * 3
#define DAYLIGHT_OFFSET_SEC 0
#define NTP_SERVER "pool.ntp.org"

// #define SETTINGS_RESET
#define ENABLE_DEBUG


#ifdef ENABLE_DEBUG
    #define __DEBUG(FMT, ...) log_printf("__DEBUG: " FMT "\n", ##__VA_ARGS__)
#else
    #define __DEBUG(FMT, ...)
#endif
