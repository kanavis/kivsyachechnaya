/* System status view */
#include <ArduinoJson.h>
#include "ESPAsyncWebServer.h"

#include "webserver/views.h"


void WebServerSystemStatusView::processRequest(AsyncWebServerRequest *request) {
    DynamicJsonDocument resp(1024);
    resp["heapSize"] = ESP.getHeapSize();
    resp["heapFree"] = ESP.getFreeHeap();
    resp["psramSize"] = ESP.getPsramSize();
    resp["psramFree"] = ESP.getFreePsram();
    
    JSONReply(request, resp);
}
