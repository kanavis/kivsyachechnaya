/* On off device */

#include "globals.h"

#include "webserver/views.h"


std::map<std::string, OnOffDevice**> WebServerDeviceOnoffSetView::deviceMap = {
    {"nebula1", &Nebula_1}
};

void WebServerDeviceOnoffSetView::processRequest(AsyncWebServerRequest* request) {
    if (!request->hasParam("device")) {
        return errorReply(request, "Required parameter: device", 400);
    }
    if (!request->hasParam("state")) {
        return errorReply(request, "Required parameter: state", 400);
    }
    
    std::string device = std::string(request->getParam("device")->value().c_str());
    std::string state = std::string(request->getParam("state")->value().c_str());
    bool on;
    if (
        state == "on" ||
        state == "ON" ||
        state == "1"
    ) {
        on = true;
    } else if (
        state == "off" ||
        state == "OFF" ||
        state == "0"
    ) {
        on = false;
    } else {
        return errorReply(request, "Wrong value for state, should be 0/1/on/off", 400);
    }

    auto search = deviceMap.find(device);
    if (search == deviceMap.end()) {
        return errorReply(request, "No such device " + device, 404);
    }

    if (on) {
        __DEBUG("Setting device %s to on", device.c_str());
        (*deviceMap[search->first])->enable();
    } else {
        __DEBUG("Setting device %s to off", device.c_str());
        (*deviceMap[search->first])->disable();
    }

    successReply(request);
}
