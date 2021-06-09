/* System status view */
#include <ArduinoJson.h>
#include "ESPAsyncWebServer.h"

#include "webserver/views.h"


void http_view_system_status(AsyncWebServerRequest *request) {
    DynamicJsonDocument resp(1024);
    resp["heapSize"] = ESP.getHeapSize();
    resp["heapFree"] = ESP.getFreeHeap();
    resp["psramSize"] = ESP.getPsramSize();
    resp["psramFree"] = ESP.getFreePsram();
    
    String r;
    serializeJson(resp, r);
    request->send(200, "text/plain", r);
}
