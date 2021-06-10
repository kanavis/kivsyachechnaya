/* Webserver views header */
#pragma once

#include "ESPAsyncWebServer.h"

#include "WebServerView.h"



/* Basic */
class WebServerPingView: public WebServerView {void processRequest(AsyncWebServerRequest* request);};


/* RPC */
/* Basic */
class WebServerSystemStatusView: public WebServerView {void processRequest(AsyncWebServerRequest* request);};

/* Sensors */
class WebServerGetAllReadingsView: public WebServerView {void processRequest(AsyncWebServerRequest* request);};


/* Errors */
class WebServer500TestView: public WebServerView {void processRequest(AsyncWebServerRequest* request);};
class WebServerNotFoundView: public WebServerView {void processRequest(AsyncWebServerRequest* request);};
