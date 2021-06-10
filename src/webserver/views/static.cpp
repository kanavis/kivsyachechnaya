/* Webserver ping view */
#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"

#include "globals.h"
#include "kivsyachechnaya.h"

#include "webserver/WebServerView.h"
#include "webserver/static.h"


const String STATIC_ROOT_DIR("/ws");


class WebServerStaticView: public WebServerView {
private:
    std::string _path;
    std::string _contentType;
    std::string _serverPath;
    std::string _getServerPath() {
        return _serverPath.length() > 0 ? _serverPath : _path;
    }

public:
    WebServerStaticView(std::string path, std::string contentType, std::string serverPath = "")
    :_path(path), _contentType(contentType), _serverPath(serverPath) {}

    void processRequest(AsyncWebServerRequest* request) {
        __DEBUG("webServer: GET %s: static from path %s: %s", _getServerPath().c_str(), _path.c_str(), _contentType.c_str());
        request->send(SPIFFS, STATIC_ROOT_DIR + String(_path.c_str()), String(_contentType.c_str()));
    }

    void bindToServer(AsyncWebServer* serverObj) {
        serverObj->on(_getServerPath().c_str(), HTTP_GET, this->asView());
    }
};


void start_webserver_static_app() {
    // Index
    (new WebServerStaticView("/index.html", "text/html; charset=utf-8", "/"))->bindToServer(webServer);

    // Meta, favicons
    (new WebServerStaticView("/robots.txt", "text/html; charset=utf-8"))->bindToServer(webServer);
    (new WebServerStaticView("/site.webmanifest", "text/html; charset=utf-8"))->bindToServer(webServer);
    (new WebServerStaticView("/favicon.ico", "image/x-icon"))->bindToServer(webServer);
    (new WebServerStaticView("/static/fav/16x16.png", "image/png"))->bindToServer(webServer);
    (new WebServerStaticView("/static/fav/32x32.png", "image/png"))->bindToServer(webServer);
    (new WebServerStaticView("/static/fav/a-t.png", "image/png"))->bindToServer(webServer);
    (new WebServerStaticView("/static/fav/ac-192x192.png", "image/png"))->bindToServer(webServer);
    (new WebServerStaticView("/static/fav/ac-512x512.png", "image/png"))->bindToServer(webServer);

    // Site static
    (new WebServerStaticView("/static/fav/ac-192x192.png", "text/html; charset=utf-8"))->bindToServer(webServer);
    (new WebServerStaticView("/static/css/styles.css", "text/css; charset=utf-8"))->bindToServer(webServer);
    (new WebServerStaticView("/static/js/jquery.min.js", "text/javascript; charset=utf-8"))->bindToServer(webServer);
    (new WebServerStaticView("/static/js/scripts.js", "text/javascript; charset=utf-8"))->bindToServer(webServer);
}
