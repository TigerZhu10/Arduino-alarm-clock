#include "Buzzer.h"

#define Buzzer_pin 14//A0 pin

bool Button_state = false;

unsigned long currentButton_latency = 0;
unsigned long pastButton_latency = 0;


int past_Buzzer_Realtime = 0;

void Buzzer_Init(){
    pinMode(Buzzer_pin,OUTPUT);
    digitalWrite(Buzzer_pin,LOW);
}

void Buzzer_on(){
    currentButton_latency = millis();
    if(currentButton_latency - pastButton_latency >= 1000){
        Button_state = !Button_state;
        Serial.println("some body care but some body don't");
        pastButton_latency = currentButton_latency;
    }
    digitalWrite(Buzzer_pin, Button_state);

}

void Buzzer_off(){
    Button_state = false;
    digitalWrite(Buzzer_pin, LOW);
}





 