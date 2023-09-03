#include "5641AS.h"

int a = 5;
int b = 6;
int c = 9;
int d = 8;
int e = 7;
int f = 4;
int g = 10;
int d1 = 15;//A1 Pin

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

void display(int num){
    for(int i = 0; i < 7; i++){
        digitalWrite(Segment[i],number[num][i]);
    }
}

void LED_Init(void) {

    for(int i = 0;i < 7;i++){
        pinMode(Segment[i], OUTPUT);
    }

     pinMode(A1, OUTPUT);             
     pinMode(A2, OUTPUT);
     pinMode(A3, OUTPUT);
     pinMode(A4, OUTPUT);


    // void LED_clear();{
    //     digitalWrite(4,LOW);
    //     digitalWrite(5,LOW);
    //     digitalWrite(6,LOW);
    //     digitalWrite(7,LOW);
    //     digitalWrite(8,LOW);
    //     digitalWrite(9,LOW);
    //     digitalWrite(10,LOW);
    // }




}

void LED_on(void){
    digitalWrite(A1,HIGH);
    digitalWrite(A2,HIGH);
    digitalWrite(A3,HIGH);
    digitalWrite(A4,HIGH);


    digitalWrite(A1,LOW);
    digitalWrite(A2,HIGH);
    digitalWrite(A3,HIGH);
    digitalWrite(A4,HIGH);

    // for(int i = 0; i < 10; i++){
    //     display(i);
    //     delay(1000);
    // }
    display(9);
    delay(1000);
         

}

