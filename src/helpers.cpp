//
// Created by filip on 07.11.20.
//

#include <HID.h>
#include "helpers.h"

const int BUZZER_PIN = 3;
const int POWER_PIN = 4; // GREEN
const int UPDATE_PIN = 8; // YELLOW

void setup_leds() {
    pinMode(POWER_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(UPDATE_PIN, OUTPUT);
}

void set_power_led(int logic_level) {
    digitalWrite(POWER_PIN, logic_level);
}

void set_update_led(int logic_level) {
    digitalWrite(UPDATE_PIN, logic_level);
}

void buzz() {
    tone(BUZZER_PIN, 500);
}

void stop_buzz() {
    noTone(BUZZER_PIN);
}

/* Updates Green Power Led => If no message has been received since more than two seconds,
 * the power led is set to LOW */
void update_power_led(uint32_t last_update) {
    if (millis() - last_update > 2000) {
        buzz();
        set_power_led(LOW);
    } else {
        stop_buzz();
        set_power_led(HIGH);
    }
}