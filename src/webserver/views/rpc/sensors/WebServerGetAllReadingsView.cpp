/* System status view */
#include <ArduinoJson.h>
#include "ESPAsyncWebServer.h"

#include "globals.h"

#include "webserver/views.h"


void WebServerGetAllReadingsView::processRequest(AsyncWebServerRequest *request) {
    DynamicJsonDocument resp(1024);
    resp["bmp280_1"] = DynamicJsonDocument(1024);
    resp["bmp280_1"]["temperature"] = BMP280_1->readTemperature();
    resp["bmp280_1"]["pressure"] = BMP280_1->readPressure();
    resp["bmp280_1"]["alt"] = BMP280_1->readAltitude(1013);

    JSONReply(request, resp);
}
