/* Main loop */
#include "globals.h"


void tick() {
    networking->tick();
    terrarium->tick();
}


void main_loop() {
    tick();
    sleep(1);
    /*
    esp_sleep_enable_timer_wakeup(10 * 1000000);
    esp_light_sleep_start();
    */
}
