#include "push_button.h"


bool Button_Flag_1 = false;
unsigned long currentMillis = 0;

bool left_LED(){
     if(digitalRead(2) == LOW && Button_Flag_1==true){
        Serial.println("test");
        return true;
    }

        return false;
     
}

void first_button(){
    if (millis() - currentMillis) {
    button1Pressed = true;
  }
  currentMillis = millis();
}




void Button_Init(){

    pinMode(2,INPUT);
    attachInterrupt(0,first_button,RISING);
}