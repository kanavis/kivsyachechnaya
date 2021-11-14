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
    Serial.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    Serial.println("!!!!!!! SETUP WAS NOT COMPLETE. Unpredictable behaviour !!!!!!!");
    Serial.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    delay(10000);
  }
}

void loop() {
  try {
    main_loop();
  } catch (std::runtime_error e) {
    Serial.print("Main loop error: ");
    Serial.println(e.what());
    Serial.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    Serial.println("!!!!!!! MAIN LOOP CRASHED !!!!!!!");
    Serial.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    delay(3000);
  }
  delay(MAIN_LOOP_DELAY);
}
