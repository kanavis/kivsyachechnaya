/* Main */

#include <stdexcept>
#include "Arduino.h"

#include "setup/setup.h"
#include "helpers/string.h"


void setup() {
  Serial.begin(115200);
  try {
    _setup();
  } catch (std::runtime_error e) {
    Serial.print(string_format("Setup error: %s", e).c_str());
  }
}

void loop() {

}
