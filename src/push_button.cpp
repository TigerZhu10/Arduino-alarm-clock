#include "push_button.h"


bool Button_Flag_1 = false;
bool Button_Flag_2 = false;
unsigned long currentMillis_1 = 0;
unsigned long currentMillis_2 = 0;
const unsigned long debounce_stoper = 100;


bool left_Button_Release(){
     if(Button_Flag_1 && digitalRead(2) == LOW ){
        return true;
    }
    return false;
     
}

bool right_Button_Release(){
     if(Button_Flag_2 && digitalRead(3) == LOW ){
        return true;
    }
    return false;
     
}

void first_button(){
    if (millis() - currentMillis_1 > debounce_stoper) {
        Button_Flag_1 = true;
    } 
    currentMillis_1 = millis();
}

void second_button(){
    if (millis() - currentMillis_2 > debounce_stoper) {
        Button_Flag_2 = true;
    } 
    currentMillis_2 = millis();
}




void Button_Init(){
    pinMode(2,INPUT);
    pinMode(3,INPUT);
    attachInterrupt(0,first_button,RISING);
    attachInterrupt(1,second_button,RISING);
}