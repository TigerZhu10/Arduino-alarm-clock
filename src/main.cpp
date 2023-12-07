#include <Arduino.h>
#include "5641AS.h"
#include "push_button.h"
#include "Buzzer.h"
#include <TimeLib.h>


int currentState = 0;

int buzzer_state = 1;


unsigned long currentMillis_latency = 0;


void setup() {
    Serial.begin(9600);
    LED_Init(); 
    Button_Init();
    Buzzer_Init();
}

void loop() {

    switch (currentState){
     case 0:
        Display_Realtime();
        if(Alarm_triggerd() && buzzer_state == 1){
            currentMillis_latency = millis();   
            currentState = 3;
        }
        if(Alarm_resume()){
            buzzer_state = 1;
        }

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
        
        Flash_Realtime(); 
                
        /*
        OBJECTIVE: if nothing is touching in 3 second than go back to case 0(display real time) 
        PARMETER: void
        NOTE: Use millis to solve the problem. 
        */
        if (millis() - currentMillis_latency >= 3000) {    
            currentState = 0;
            Realtime_Position = 0;
        }
        
        if(left_Button_Release()){
            currentMillis_latency = millis();
            Realtime_counter = 1;
            Realtime_Position++;
            if(Realtime_Position > 3){
                currentState = 2;             
                Realtime_Position = 0;               
                Realtime_counter = 0;
            }
            Button_Flag_1 = false;
        }else if(right_Button_Release()){     
                currentMillis_latency = millis();
                Time_change_Inc();
                Button_Flag_2 = false;
        }

        break;


     case 2: 
         
        display_alarm_time();

        if (millis() - currentMillis_latency >= 3000) {    
            currentState = 0;
            currentPosition = 0;
        }

        if(left_Button_Release()){
            currentMillis_latency = millis();
            Alarm_counter = 1;
            currentPosition++;
            if(currentPosition > 3){             
                currentPosition = 0;
                currentState = 0;
                Alarm_counter = 0;
            }
            Button_Flag_1 = false;         
        }else if(right_Button_Release()){
                currentMillis_latency = millis();
                Alarmtime_Inc();
                Button_Flag_2 = false;
                
        } 

        break;

     case 3:
        buzzer_state = 0;

        Display_Realtime();

        Buzzer_on();

        currentState = 4;


        break;

     case 4:

        if (millis() - currentMillis_latency >= 30000) {  
            buzzer_state = 0;
            Buzzer_off();
        }

        if(left_Button_Release()){
            buzzer_state = 0;
            Buzzer_off();
            currentState = 0; 
            Button_Flag_1 = false;

        }else{
            currentState = 3;
        }


        break;

        

    default:

        break;
    
}
    }


