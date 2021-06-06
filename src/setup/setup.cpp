/* Setup process */
#include "setup.h"
#include "setup_state.h"
#include "setup_wifi.h"


void _setup() {
    setup_state();
    setup_wifi();
}