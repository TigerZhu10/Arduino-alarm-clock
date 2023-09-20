#include <Arduino.h>
#include "5641AS.h"
#include "push_button.h"
#include <TimeLib.h>


void setup() {
    Serial.begin(9600);
    LED_Init();
    Button_Init();
}

void loop() {

    Display_Realtime();

}
