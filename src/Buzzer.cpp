#include "Buzzer.h"

int Buzzer_pin = 14;//A0 pin


int past_Buzzer_Realtime = 0;

void Buzzer_Init(){
    pinMode(Buzzer_pin,OUTPUT);
    digitalWrite(Buzzer_pin,LOW);
}

void Buzzer_on(){
    unsigned long BuzzerMillis_Realtime = millis();

    if(BuzzerMillis_Realtime - past_Buzzer_Realtime >= 1000){
        digitalWrite(Buzzer_pin,HIGH);
        past_Buzzer_Realtime = BuzzerMillis_Realtime;
    }
    
   
}





 