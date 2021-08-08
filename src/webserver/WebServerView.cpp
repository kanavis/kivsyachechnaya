/* Webserver view class */
#include <ArduinoJson.h>
#include "ESPAsyncWebServer.h"
#include <functional>
#include <stdexcept>

#include "webserver/WebServerView.h"


ArRequestHandlerFunction WebServerView::asView() {
    return [this](AsyncWebServerRequest* request){ handle(request); };
}


void WebServerView::handle(AsyncWebServerRequest* request) {
    try {
        processRequest(request);
    } catch (std::runtime_error e) {
        errorReply(request, "Exception happened: " + std::string(e.what()));
    }
}

bool WebServerView::isJSONRequest(AsyncWebServerRequest* request) {
    return 
        request->hasHeader("Accept") &&
        request->header("Accept").equalsIgnoreCase("application/json")
    ;
}

void WebServerView::reply(AsyncWebServerRequest* request, std::string data, int code) {
    request->send(code, "text/plain", String(data.c_str()));
}

void WebServerView::successReply(AsyncWebServerRequest* request) {
    if (isJSONRequest(request)) {
        DynamicJsonDocument resp(1024);
        resp["status"] = "OK";
        JSONReply(request, resp);
    } else {
        request->send(200, "text/plain", "OK");
    }
}

void WebServerView::JSONReply(AsyncWebServerRequest* request, DynamicJsonDocument resp, int code) {
    String r;
    serializeJson(resp, r);
    request->send(code, "application/json", r);
}

void WebServerView::errorReply(AsyncWebServerRequest* request, std::string error, int code) {
    if (isJSONRequest(request)) {
        DynamicJsonDocument resp(1024);
        resp["error"] = error;
        JSONReply(request, resp);
    } else {
        request->send(500, "text/plain", String(error.c_str()));
    }
}
