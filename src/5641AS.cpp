#include "5641AS.h"

int a = 5;
int b = 6;
int c = 9;
int d = 8;
int e = 7;
int f = 4;
int g = 10;
int d1 = 15;//A1 Pin
int d2 = 16;//A2 pin
int d3 = 17;//A3 pin
int d4 = 18;//A4 pin

int pos_control [4] = {d1, d2, d3, d4};

int Segment [7] = {a,b,c,d,e,f,g};



int number [10][7] = {
   //a  b  c  d  e  f  g
    {1, 1, 1, 1, 1, 1, 0},//NUMBER 0
    {0, 1, 1, 0, 0, 0, 0},//NUMBER 1
    {1, 1, 0, 1, 1, 0, 1},//NUMBER 2
    {1, 1, 1, 1, 0, 0, 1},//NUMBER 3
    {0, 1, 1, 0, 0, 1, 1},//NUMBER 4
    {1, 0, 1, 1, 0, 1, 1},//NUMBER 5
    {1, 0, 1, 1, 1, 1, 1},//NUMBER 6
    {1, 1, 1, 0, 0, 0, 0},//NUMBER 7
    {1, 1, 1, 1, 1, 1, 1},//NUMBER 8
    {1, 1, 1, 1, 0, 1, 1},//NUMBER 9
};

void DisplaySingle(int pos, int num){
    if(pos == 1){
        pos = d1;
    }

    if(pos == 2){
        pos = d2;
    }

    if(pos == 3){
        pos = d3;
    }

    if(pos == 4){
        pos = d4;
    }
    digitalWrite(pos, LOW);

    for(int i = 0; i < 7; i++){
        digitalWrite(Segment[i],number[num][i]);
    }
}

void Led_clear(void){
    digitalWrite(d1,HIGH);
    digitalWrite(d2,HIGH);
    digitalWrite(d3,HIGH);
    digitalWrite(d4,HIGH);

    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);

} 





void LED_Init(void) {

    for(int i = 0;i < 7;i++){
        pinMode(Segment[i], OUTPUT);
    }

    for(int i = 0;i < 4;i++){
        pinMode(pos_control[i], OUTPUT);
        digitalWrite(pos_control[i], HIGH);
    }

}

void LED_on(void){





    DisplaySingle(1,1);
    delay(5);

    Led_clear();

    DisplaySingle(2,6);
    delay(5);
    
    Led_clear();

    DisplaySingle(3,8);
    delay(5);

    Led_clear();

    DisplaySingle(4,2);
    delay(5);
    
    Led_clear();
         

}

