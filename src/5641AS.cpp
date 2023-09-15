#include "5641AS.h"
#include <TimeLib.h>

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

/*
OBJECTIVE: Display a wanted number at designated location.
PARAMETER: 
    pos: displayed location
    num: display number
NOTE: void
*/
void DisplaySingle(int pos, int num){
    digitalWrite(pos_control[pos], LOW);

    for(int i = 0; i < 7; i++){
        digitalWrite(Segment[i],number[num][i]);
    }
}
/*
OBJECTIVE: Clear all the LED.
PARMETER: void
NOTE: Be care the state of the LED It should be not MAKE the LED light up
*/
void Led_clear(void){

    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);

} 


/*
OBJECTIVE: setup the LED using for loop
PARMETER: void
NOTE: we use "for"to set up the mode of the pin. First we made a array and a virable letter "i" because there are 7 letters that we have to set. So it should be smaller than 7.
We don't have to do i++ yet that's the last step. Just like before pinMode start, put the name of the array in the bracket and ues i to call the name. write OUTPUT in there.
Lastly just i++. The second one is the same as the first. 
*/


void LED_Init(void) {

    for(int i = 0;i < 7;i++){
        pinMode(Segment[i], OUTPUT);
    }

    for(int i = 0;i < 4;i++){
        pinMode(pos_control[i], OUTPUT);
        digitalWrite(pos_control[i], HIGH);
    }
}
/*
OBJECTIVE: make a function that we can transfer it if we need it
PARMETER: void
NOTE: The minute(); and the second(); is for us to light up the number 1-9. Because we have to call them so we have to write a name for it like digits[0]

*/

void Time_set(){
    digits[0] = minute() / 10;
    digits[1] = minute() % 10;
    digits[2] = second() / 10;
    digits[3] = second() % 10;
}

int digits[4] = {0,0,0,0};
int first_number = 0;
int second_number = 0;
int third_number = 0;
int fourth_number = 0;
int display_digit [4] = {first_number, second_number, third_number, fourth_number};



/*
OBJECTIVE: Display the real number by the clock form.
PARMETER: void
NOTE: void(for now)
*/
void Display_Realtime(){


        // int fourth_number = second();
        // int third_number = second();
        // int second_number = minute();
        // int first_number = minute();


        Time_set();
      for(int i = 0; i < 4; i++){
        
        DisplaySingle(i,digits[i]);
        Led_clear();
        digitalWrite(pos_control[i],HIGH);
      }
       


     //  int fourth_number = second();
     //  fourth_number = fourth_number % 10;
    //   DisplaySingle(3,fourth_number);
    //   Led_clear();
    //   digitalWrite(pos_control[3], HIGH);
    //   int third_number = second();
    //   third_number = third_number/10;
    //   DisplaySingle(2,third_number);
    //   Led_clear();
    //   digitalWrite(pos_control[2], HIGH);

    //   int second_number = minute();
    //   second_number = second_number % 10;
    //   DisplaySingle(1,second_number);
    //   Led_clear(); 
    //   digitalWrite(pos_control[1], HIGH);
    //   int first_number = minute(); 
    //   first_number = first_number/10;
    //   DisplaySingle(0,first_number);
    //   Led_clear();
    //   digitalWrite(pos_control[0], HIGH);



    //  for(int i = 0; i < 4; i++){
    //     DisplaySingle(i,display_digit[i]);
    //     Led_clear();
    //     digitalWrite(pos_control[i],HIGH);
        
    //   }
    

}

