/* Webserver ping view */
#include "ESPAsyncWebServer.h"

#include "webserver/views.h"


void http_view_ping(AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "PONG");
}
