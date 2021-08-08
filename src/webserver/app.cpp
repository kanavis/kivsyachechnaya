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
    webServer->on("/api/1/sensors/get/", HTTP_GET, (new WebServerGetReadingsView)->asView());
    webServer->on("/api/1/sensors/get/all/", HTTP_GET, (new WebServerGetAllReadingsView)->asView());

    /* Devices */
    webServer->on("/api/1/outputs/onoff/set/", HTTP_GET, (new WebServerDeviceOnoffSetView)->asView());

    /* Errors */
    webServer->on("/500test/", HTTP_GET, (new WebServer500TestView())->asView());
    webServer->onNotFound((new WebServerNotFoundView())->asView());
}
