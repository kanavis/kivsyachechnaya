/* 
* Storage header
* 
* Storage structure:
*   0-6      (8)  MAGIC WORD "MAGIC!"
*   7-104    (98) wifi credentials
*/
#include "classes/constraints.h"
#include "classes/wifi.h"


#define STORAGE_MAGIC "MAGIC!"
#define STORAGE_SIZE 1000000
#define WIFI_ADDR 7


class Storage {
private:
    static const size_t wifi_ssid_address = WIFI_ADDR;
    static const size_t wifi_password_address = WIFI_ADDR + 1 + WIFI_MAX_SSID_LENGTH;
public:
    static bool hasMagic();
    static void setMagic();
    static void saveWifiCredentials(WifiCredentials credentials);
    static WifiCredentials loadWifiCredentials();
};
