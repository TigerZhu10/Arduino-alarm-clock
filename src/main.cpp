#include <Arduino.h>
#include "5641AS.h"
#include "push_button.h"
#include <TimeLib.h>


int currentState = 0;

int Millis_counter = 0;
unsigned long currentMillis_latency = 0;

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
            currentMillis_latency = millis();          
            currentState = 1;
            Button_Flag_1 = false; 
        }else if(right_Button_Release()){
            currentState = 0;
            Button_Flag_2 = false;
        }

        break;
    
    case 1: 
        //if push button is not pressed within 3s
        //go back to state 0
        if (millis() - currentMillis_latency >= 3000) {    
            currentState = 0;
            currentPosition = 0;
        }
      
        display_alarm_time();
        
        if(left_Button_Release()){
            Alarm_counter = 1;
            if(currentPosition > 3){             
                currentPosition = 0;
                currentState = 0;
                Alarm_counter = 0;
            }
            currentPosition++;
            Millis_counter = 1;
            currentMillis_latency = millis();
            Button_Flag_1 = false;
        }
        else if(right_Button_Release()){
            Alarmtime_Inc();
            Button_Flag_2 = false;
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


