/* Webserver view class */
#pragma once

#include <ArduinoJson.h>
#include "ESPAsyncWebServer.h"


class WebServerView {
private:
    void handle(AsyncWebServerRequest* request);
    virtual void processRequest(AsyncWebServerRequest* request);

protected:    
    bool isJSONRequest(AsyncWebServerRequest* request);
    void JSONReply(AsyncWebServerRequest* request, DynamicJsonDocument resp);

public:
    WebServerView() {}
    ArRequestHandlerFunction asView();
};
