/* Main loop */
#include "globals.h"


void tick() {
    networking->tick();
}


void main_loop() {
    tick();
}
