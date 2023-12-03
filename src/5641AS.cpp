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

unsigned long past_Millis_flash = 0;
unsigned long past_Millis_Realtime = 0;
unsigned int Alarm_counter = 0;
unsigned int Realtime_counter = 0;
int currentPosition = 0;
int Realtime_Position = 0;
unsigned int Flash_counter = 0;

int pos_control [4] = {d1, d2, d3, d4};

int Segment [7] = {a,b,c,d,e,f,g};

//Time_set();
int digits[4] = {0,0,0,0};
int Alarm_digits[4] = {0,0,0,1};

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
    //change the location
    digitalWrite(pos_control[pos], LOW);

    //change the number
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
    digits[0] = hour() / 10;
    digits[1] = hour() % 10;
    digits[2] = minute() / 10;
    digits[3] = minute() % 10;
}


/*
OBJECTIVE: Display the real number by the clock form.
PARMETER: void
NOTE: void
*/
void Display_Realtime(){

    Time_set();

    for(int i = 0; i < 4; i++){    
        DisplaySingle(i,digits[i]);
        Led_clear();
        digitalWrite(pos_control[i],HIGH);
    } 
}

void Flash_Realtime(){
    unsigned long currentMillis_Realtime = millis();

    if (currentMillis_Realtime - past_Millis_Realtime >= 500) {
        Realtime_counter++;
        past_Millis_Realtime = currentMillis_Realtime;       
    } 
    
    bool Realtime_digits = ((Realtime_counter % 2) == 0);

    if (Realtime_digits) {
        Display_Realtime();
    }else{  
        for(int i = 0; i < 4; i++){
            if( i != Realtime_Position){
                DisplaySingle(i, digits[i]);
            }

        Led_clear();
        digitalWrite(pos_control[i], HIGH);
        }

    }
      
}  

/*
OBJECTIVE: make the light flashand using current_postion swich spot. 
PARMETER: void
NOTE: void
*/
void display_alarm_time(){
    
    unsigned long currentMillis_flash = millis();

    if(currentMillis_flash - past_Millis_flash >= 500) {
        Alarm_counter++;
        past_Millis_flash = currentMillis_flash;     
    } 

    bool displaydigits = ((Alarm_counter % 2) == 0);

    for(int i = 0; i < 4; i++){
        if (displaydigits) {
            DisplaySingle(i, Alarm_digits[i]);
        }
        else{
        if( i != currentPosition){
            DisplaySingle(i, Alarm_digits[i]);
        }


    }
    Led_clear();
    digitalWrite(pos_control[i], HIGH);  

    }  

   
}

/*
OBJECTIVE: add the number from the position the current_position is. 
PARMETER: void
NOTE: void
*/
void Alarmtime_Inc(){
          
    Alarm_digits[currentPosition]++;

    //if the digits are bigger than 9 than go back to 0.
    if(Alarm_digits[0] > 1){
        Alarm_digits[0] = 0;
    }

    if(Alarm_digits[1] > 9){
        Alarm_digits[1] = 0;
    }

    if(Alarm_digits[1] > 2 && Alarm_digits[0] == 1){
        Alarm_digits[1] = 0;
    }

    if(Alarm_digits[2] > 9){
        Alarm_digits[2] = 0;
    }

    if(Alarm_digits[3] > 9){
        Alarm_digits[3] = 0;
    }
    
    
}

void Time_change_Inc(){

    int counter_minute = minute(); 
    int counter_hour = hour();

       

    if(Realtime_Position == 0){
        counter_hour = counter_hour + 10;
        if(counter_hour > 23 ){
        counter_hour = 0;
        } 
    }  
    if(Realtime_Position == 1){
        counter_hour++;
    }
    if(Realtime_Position == 2){
        counter_minute = counter_minute + 10;
        if(counter_minute > 59 ){
            counter_minute = 0;
        } 
    }
    if(Realtime_Position == 3){
        counter_minute++;
    }
    

    setTime(counter_hour,counter_minute,0,0,0,0);



}

 