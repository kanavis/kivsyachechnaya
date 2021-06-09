/* Setup process */
#include "setup/setup.h"
#include "setup/setup_settings.h"
#include "setup/setup_wifi.h"
#include "setup/setup_ntp.h"


void _setup() {
    setup_settings();
    setup_wifi();
    setup_ntp();
}
