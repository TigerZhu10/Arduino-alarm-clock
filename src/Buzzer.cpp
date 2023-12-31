#include "Buzzer.h"
#include "5641AS.h"

#define Buzzer_pin 14//A0 pin

bool Button_state = false;

unsigned long currentButton_latency = 0;
unsigned long pastButton_latency = 0;

int Buzzer_digits [4] = {0,0,0,0};



int past_Buzzer_Realtime = 0;

void Buzzer_Init(){
    pinMode(Buzzer_pin,OUTPUT);
    digitalWrite(Buzzer_pin,LOW);
}

void Buzzer_on(){
    currentButton_latency = millis();
    if(currentButton_latency - pastButton_latency >= 1000){
        Button_state = !Button_state;
        pastButton_latency = currentButton_latency;
    }
    digitalWrite(Buzzer_pin, Button_state);

}

void Buzzer_off(){
    digitalWrite(Buzzer_pin, LOW);
}

bool Alarm_triggerd(){

    if(digits[0] == Alarm_digits[0]){
        if(digits[1] == Alarm_digits[1]){
            if(digits[2] == Alarm_digits[2]){
                if(digits[3] == Alarm_digits[3]){
                    return true;
                }
            }
        }   
    }
    return false;
}

bool Alarm_resume(){
    for(int i = 0; i < 4; i++){
        Buzzer_digits [i] = Alarm_digits [i];
    }
    Buzzer_digits[3]++;

    if(digits[0] == Buzzer_digits[0]){
        if(digits[1] == Buzzer_digits[1]){
            if(digits[2] == Buzzer_digits[2]){
                if(digits[3] == Buzzer_digits[3]){
                    return true;
                }
            }
        }   
    }
    return false;
}





 