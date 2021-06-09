/* Webserver application */
#include "ESPAsyncWebServer.h"

#include "globals.h"
#include "kivsyachechnaya.h"

#include "webserver/views.h"
#include "webserver/app.h"


void start_webserver_app() {
    /* Basic */
    webServer->on("/ping/", HTTP_GET, http_view_ping);
    webServer->on("/system_status/", HTTP_GET, http_view_system_status);
}
