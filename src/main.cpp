/* Main */
#include <Arduino.h>
#include <EEPROM.h>
#include <stdexcept>

#include "kivsyachechnaya.h"
#include "main_loop.h"
#include "setup/setup.h"


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
  try {
    main_loop();
  } catch (std::runtime_error e) {
    Serial.print("Main loop error: ");
    Serial.println(e.what());
  }
  delay(MAIN_LOOP_DELAY);
}
