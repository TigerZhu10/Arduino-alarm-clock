#include "push_button.h"


bool Button_Flag_1 = false;
unsigned long currentMillis = 0;
const unsigned long debounce_stoper = 100;

bool left_Button_Release(){
     if(Button_Flag_1 && digitalRead(2) == LOW ){
        return true;
    }
    return false;
     
}

void first_button(){
    if (millis() - currentMillis > debounce_stoper) {
        Button_Flag_1 = true;
    } 
    currentMillis = millis();
}




void Button_Init(){
    pinMode(2,INPUT);
    attachInterrupt(0,first_button,RISING);
}