/* Webserver application */
#include "ESPAsyncWebServer.h"

#include "globals.h"
#include "kivsyachechnaya.h"

#include "webserver/app.h"
#include "webserver/views.h"



void start_webserver_app() {
    /* Basic */
    webServer->on("ping/", HTTP_GET, (new WebServerPingView())->asView());


    /* RPC */
    /* Basic */
    webServer->on("/api/1/system_status/", HTTP_GET, (new WebServerSystemStatusView)->asView());

    /* Sensors */
    webServer->on("/api/1/sensors/get_all/", HTTP_GET, (new WebServerGetAllReadingsView)->asView());

    /* Errors */
    webServer->on("/500test/", HTTP_GET, (new WebServer500TestView())->asView());
    webServer->onNotFound((new WebServerNotFoundView())->asView());
}
