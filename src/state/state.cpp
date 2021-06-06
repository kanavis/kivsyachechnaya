/* State implementation */
#include "state.h"


KyState::KyState(WifiCredentials* wifi_credentials) {
    this->wifi_credentials = wifi_credentials;
}


KyState* g_state = NULL;
