/* System status view */
#include <string>

#include <ArduinoJson.h>
#include "ESPAsyncWebServer.h"

#include "globals.h"
#include "helpers/string_helpers.h"
#include "webserver/adapters.h"

#include "webserver/views.h"


std::map<std::string, ISensorAdapter*> WebServerGetReadingsView::deviceMap = {
    {"bme280_1", new BME280Adapter(&BME280_1)}
};

void WebServerGetReadingsView::processRequest(AsyncWebServerRequest *request) {
    if (!request->hasParam("sensor")) {
        return errorReply(request, "Required parameter: sensor", 400);
    }
    if (!request->hasParam("reading")) {
        return errorReply(request, "Required parameter: reading", 400);
    }
    std::string sensor = std::string(request->getParam("sensor")->value().c_str());
    std::string reading = std::string(request->getParam("reading")->value().c_str());
    
    auto search = deviceMap.find(sensor);
    if (search == deviceMap.end()) {
        return errorReply(request, "No such sensor " + sensor, 404);
    }
    ISensorAdapter* adapter = deviceMap[search->first];
    if (!adapter->hasReading(reading)) {
        return errorReply(request, "No such reading " + reading + " for sensor " + sensor, 404);
    }

    __DEBUG("Request sensor %s reading %s", sensor.c_str(), reading.c_str());
    double value = adapter->getReading(reading);
    if (isJSONRequest(request)) {
        DynamicJsonDocument resp(1024);
        resp[sensor] = DynamicJsonDocument(1024);
        resp[sensor][reading] = value;
        JSONReply(request, resp);
    } else {
        reply(request, to_string(value));
    }
}


void WebServerGetAllReadingsView::processRequest(AsyncWebServerRequest* request) {
    DynamicJsonDocument resp(1024);
    __DEBUG("Request all sensors");

    resp["bme280_1"] = DynamicJsonDocument(1024);
    resp["bme280_1"]["temperature"] = BME280_1->readTemperature();
    resp["bme280_1"]["pressure"] = BME280_1->readPressure();
    resp["bme280_1"]["altitude"] = BME280_1->readAltitude(1013);
    resp["bme280_1"]["humidity"] = BME280_1->readHumidity();

    JSONReply(request, resp);
}
