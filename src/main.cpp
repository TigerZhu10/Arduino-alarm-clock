#include <Arduino.h>
#include "5641AS.h"
#include <TimeLib.h>


void setup() {
    Serial.begin(9600);
    LED_Init();
}

void loop() {

    Display_Realtime();

}
