/* CLI inputs header */
#pragma once

#include <string>

#include "settings_cls/SystemSettings.h"


namespace Inputs {
    bool expect_enter(std::string message, uint timeout = 5);
    SystemSettings* system_settings();
};
