/* Setup process */
#include "setup.h"
#include "setup_settings.h"
#include "setup_wifi.h"


void _setup() {
    setup_settings();
    setup_wifi();
}
