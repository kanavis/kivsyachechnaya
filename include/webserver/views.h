/* Webserver views header */
#pragma once

#include <map>
#include <memory>

#include "devices/DeviceSimpleOutput.h"
#include "ESPAsyncWebServer.h"
#include "webserver/adapters.h"
#include "WebServerView.h"


/* Basic */
class WebServerPingView: public WebServerView {void processRequest(AsyncWebServerRequest* request);};


/* RPC */
/* Basic */
class WebServerSystemStatusView: public WebServerView {void processRequest(AsyncWebServerRequest* request);};

/* Sensors */
class WebServerGetReadingsView: public WebServerView {
    static std::map<std::string, ISensorAdapter*> deviceMap;
    void processRequest(AsyncWebServerRequest* request);
};
class WebServerGetAllReadingsView: public WebServerView {void processRequest(AsyncWebServerRequest* request);};


/* Devices */
class WebServerDeviceOnoffSetView: public WebServerView {
    static std::map<std::string, DeviceSimpleOutput**> deviceMap;
    void processRequest(AsyncWebServerRequest* request);
};


/* Settings */
class WebServerTerrariumSettingsView: public WebServerView {void processRequest(AsyncWebServerRequest* request);};


/* Errors */
class WebServer500TestView: public WebServerView {void processRequest(AsyncWebServerRequest* request);};
class WebServerNotFoundView: public WebServerView {void processRequest(AsyncWebServerRequest* request);};
