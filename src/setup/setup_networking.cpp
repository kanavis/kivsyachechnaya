/* Wifi setup */
#include <WiFi.h>

#include "globals.h"

#include "setup/setup_networking.h"


Networking* networking;


void setup_networking() {
    networking = new Networking();
    networking->start();
}
