#include "push_button.h"


bool Button_Flag_1 = true;

void left_LED(){

    delay(150);

    if(digitalRead(2) == HIGH && Button_Flag_1==true){
        Button_Flag_1 = false;
        Serial.println("test");
    }
    delay(150);
    Button_Flag_1 =  true;

}



void Button_Init(){

    pinMode(2,INPUT);
    attachInterrupt(0,left_LED,RISING);
}