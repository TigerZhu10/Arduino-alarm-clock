#include <Arduino.h>
#include "5641AS.h"
#include "push_button.h"
#include <TimeLib.h>


int currentState = 0;
int current = 0;

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
            Button_Flag_1 = false;
            currentState = 1;
     //   Serial.println("test");

        }
        break;

    case 1:
      Serial.println("test");

        if(left_Button_Release()){
            Button_Flag_1 = false;
            currentState = 0;
        }
        break;

    default:
        break;
    }








       switch (current){
    case 0:
       // Display_Realtime();

        if(right_Button_Release()){
            Button_Flag_2 = false;
            current = 1;
     //   Serial.println("kobe");

        }
        break;

    case 1:
      Serial.println("kobe");

        if(right_Button_Release()){
            Button_Flag_2 = false;
            current = 0;
        }
        break;

    default:
        break;
    }



    }

 

    















//  if(right_Button_Release()){
//         Button_Flag_2 = false;
//         Serial.println("kobe");
//     }