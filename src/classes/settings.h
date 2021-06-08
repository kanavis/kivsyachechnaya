/* Settings header file */ 
#include <stdexcept>
#include "wifi_credentials.h"
#include "terrarium_settings.h"


class Settings {
private:
    static Settings* global_settings;
    static bool settings_initialized;

    WifiCredentials& _wifi_credentials;
    TerrariumSettings& _terrarium_settings;

public:
    Settings(WifiCredentials& wifi_credentials, TerrariumSettings& terrarium_settings)
    :_wifi_credentials(wifi_credentials)
    , _terrarium_settings(terrarium_settings)
    {};

    WifiCredentials& getWifiCredentials();
    TerrariumSettings& getTerrariumSettings();


    static Settings& getSettings();
    static void setGlobalettings(Settings& settings);
};
