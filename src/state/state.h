/* State header */
#include "classes/wifi.h"


class KyState {
public:
    KyState(WifiCredentials* wifi_credentials);

    WifiCredentials* wifi_credentials;
};
