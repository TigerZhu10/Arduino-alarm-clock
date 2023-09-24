#include <Arduino.h>
#include "5641AS.h"
#include "push_button.h"
#include <TimeLib.h>

#define DISPLAY_STATE 0
#define TEST_STATE 1

int currentState = 0;

void setup() {
    Serial.begin(9600);
    LED_Init();
    Button_Init();
}

void loop() {
    switch (currentState){
    case DISPLAY_STATE:
        Display_Realtime();

        if(left_Button_Release()){
            Button_Flag_1 = false;
            currentState = TEST_STATE;
        }
        break;

    case TEST_STATE:
        Serial.println("test");

        if(left_Button_Release()){
            Button_Flag_1 = false;
            currentState = DISPLAY_STATE;
        }
        break;

    default:
        break;
    }
    
}
