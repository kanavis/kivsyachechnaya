/* Setup webserver */
#include "globals.h"
#include "kivsyachechnaya.h"
#include "webserver/app.h"

#include "setup/setup_webserver.h"


AsyncWebServer* webServer;


void setup_webserver() {
    __DEBUG("Creating webserver on port %d", HTTP_PORT);
    webServer = new AsyncWebServer(HTTP_PORT);

    __DEBUG("Creating webserver app");
    start_webserver_app();

    __DEBUG("Starting webserver");
    webServer->begin();
}
