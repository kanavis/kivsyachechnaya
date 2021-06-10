/* Web server view 500 test */
#include <stdexcept>
#include "ESPAsyncWebServer.h"

#include "webserver/views.h"


void WebServer500TestView::processRequest(AsyncWebServerRequest* request) {
    throw std::runtime_error("Test error");
}
