/* Setup FS */
#include "SPIFFS.h"

#include "setup/setup_fs.h"

#include "kivsyachechnaya.h"


void setup_fs() {
    __DEBUG("Setup SPIFFS");
    SPIFFS.begin();
    __DEBUG("SPIFFS setup complete");
}
