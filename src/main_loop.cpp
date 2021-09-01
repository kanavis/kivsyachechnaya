/* Main loop */
#include "globals.h"


void tick() {
    networking->tick();
    terrarium->tick();
}


void main_loop() {
    tick();
}
