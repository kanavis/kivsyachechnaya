#include "setup/setup_terrarium.h"
#include "terrarium/Terrarium.h"

#include "globals.h"
#include "kivsyachechnaya.h"

Terrarium* terrarium;


void setup_terrarium() {
    __DEBUG("Start terrarium setup");
    terrarium = new Terrarium(Nebula_1);
    __DEBUG("Terrarium setup complete");
}
