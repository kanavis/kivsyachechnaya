/* System status view */
#include <ArduinoJson.h>
#include "ESPAsyncWebServer.h"

#include "globals.h"

#include "webserver/views.h"


void WebServerGetAllReadingsView::processRequest(AsyncWebServerRequest *request) {
    DynamicJsonDocument resp(1024);
    resp["dht1"] = DynamicJsonDocument(1024);
    resp["dht1"]["temperature"] = DHT1->readTemperatureWithRetries();
    resp["dht1"]["humidity"] = DHT1->readHumidityWithRetries();

    JSONReply(request, resp);
}
