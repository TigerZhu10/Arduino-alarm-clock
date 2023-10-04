#include <Arduino.h>
#include "5641AS.h"
#include "push_button.h"
#include <TimeLib.h>


int currentState = 0;

void setup() {
    Serial.begin(9600);
    LED_Init();
    Button_Init();
}

void loop() {

    switch (currentState){
    case 0:
        Display_Realtime();

        if(left_Button_Release()){
            Button_Flag_1 = false;
            currentState = 1;
        }else if(right_Button_Release()){
            Button_Flag_2 = false;
            currentState = 0;
        }

        // if(right_Button_Release()){
        //     Button_Flag_2 = false;
        //     currentState = 2;
        // }
        break;

    case 1:
        display_alarm_time();
        if(left_Button_Release()){
            Button_Flag_1 = false;
            currentState = 0;
        }else if(right_Button_Release()){
            Button_Flag_2 = false;
            currentState = 1;
        }

        break;


    case 2:
        if(right_Button_Release()){
            Button_Flag_2 = false;
            currentState = 0;
        }else if(left_Button_Release()){
            Button_Flag_1 = false;
            currentState = 2;
        } 

        break;

    default:

        break;
    }
}

