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
        if (isJSONRequest(request)) {
            DynamicJsonDocument resp(1024);
            resp["error"] = e.what();
            JSONReply(request, resp);
        } else {
            request->send(500, "text/plain", "Exception happened: " + String(e.what()));
        }
    }
}


bool WebServerView::isJSONRequest(AsyncWebServerRequest* request) {
    return 
        request->hasHeader("Accept") &&
        request->header("Accept").equalsIgnoreCase("application/json")
    ;
}


void WebServerView::JSONReply(AsyncWebServerRequest* request, DynamicJsonDocument resp) {
    String r;
    serializeJson(resp, r);
    request->send(200, "text/plain", r);
}
