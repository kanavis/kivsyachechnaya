/* Webserver 404 view */
#include "ESPAsyncWebServer.h"

#include "webserver/views.h"


void WebServerNotFoundView::processRequest(AsyncWebServerRequest* request) {
    request->send(404, "text/plain", "NOT FOUND");
}
