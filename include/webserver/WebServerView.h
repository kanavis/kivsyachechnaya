/* Webserver view class */
#pragma once

#include <exception>
#include <iostream>
#include <stdint.h>
#include <string.h>

#include <ArduinoJson.h>
#include "ESPAsyncWebServer.h"


class RequestException: public std::exception {
    const std::string _message;
    const uint8_t _code;
public:
    RequestException(const std::string message, const uint8_t code = 400):
    _code(code), _message(message) {};
    
    std::string getMessage() {return _message;}
    uint8_t getCode() {return _code;}
};


class WebServerView {
private:
    void handle(AsyncWebServerRequest* request);
    virtual void processRequest(AsyncWebServerRequest* request);

protected:    
    bool isJSONRequest(AsyncWebServerRequest* request);
    void reply(AsyncWebServerRequest* request, std::string data, int code = 200);
    void successReply(AsyncWebServerRequest* request);
    void JSONReply(AsyncWebServerRequest* request, DynamicJsonDocument resp, int code = 200);
    void errorReply(AsyncWebServerRequest* request, std::string error, int code = 500);

public:
    WebServerView() {}
    ArRequestHandlerFunction asView();
};
