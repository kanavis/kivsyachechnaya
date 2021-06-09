/* CLI inputs header */
#include <string>
#include "classes/wifi_credentials.h"


namespace Inputs {
    bool expect_enter(std::string message, uint timeout = 5);
    WifiCredentials* wifi_credentials();
};
