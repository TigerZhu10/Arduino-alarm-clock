#include <Arduino.h>
#include "5641AS.h"
#include "push_button.h"
#include <TimeLib.h>


int currentState = 0;

unsigned long past_Millis_latency = 0;
int Millis_counter = 0;

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
            currentState = 1;
            Button_Flag_1 = false;
        }else if(right_Button_Release()){
            currentState = 0;
            Button_Flag_2 = false;
        }

        // if(right_Button_Release()){
        //     Button_Flag_2 = false;
        //     currentState = 2;
        // }
        break;
    
    case 1:
    
 

    //  if(Millis_counter == 0){
    //   unsigned long currentMillis_latency = millis();
    //   if (currentMillis_latency - past_Millis_latency >= 3000) {
    //     currentState = 0;
    //      past_Millis_latency = currentMillis_latency;
        
    // }
    // } 

      
        display_alarm_time();
        
        if(left_Button_Release()){
            Alarm_counter = 1;
            currentPosition++;
            Millis_counter = 1;
            Button_Flag_1 = false;
        }
            if(currentPosition > 3){             
                currentPosition = 0;
                currentState = 0;
                Alarm_counter = 0;
            }else if(right_Button_Release()){
            currentState = 1;
            Button_Flag_2 = false;
        }
        if(Millis_counter == 0){
      unsigned long currentMillis_latency = millis();
      if (currentMillis_latency - past_Millis_latency >= 3000) {
        currentState = 0;
         past_Millis_latency = currentMillis_latency;
        
    }
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


