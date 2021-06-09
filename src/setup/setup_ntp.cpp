/* Setup NTP */
#include "time.h"
#include "kivsyachechnaya.h"
#include "setup/setup_ntp.h"


void setup_ntp() {
    configTime(GMT_OFFSET_SEC, DAYLIGHT_OFFSET_SEC, NTP_SERVER);
}
