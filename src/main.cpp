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
    Serial.print("Setup error: ");
    Serial.println(e.what());
  }
}

void loop() {

}
