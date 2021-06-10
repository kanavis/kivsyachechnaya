/* Webserver ping view */
#include "ESPAsyncWebServer.h"

#include "webserver/views.h"


void WebServerPingView::processRequest(AsyncWebServerRequest* request) {
    request->send(200, "text/plain", "PONG");
}
