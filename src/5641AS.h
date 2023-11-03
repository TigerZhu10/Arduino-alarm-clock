#include <Arduino.h>
void LED_Init(void);
void Display_Realtime(void);
void display_alarm_time(void);
void Alarmtime_Inc(void);
void Flash_Realtime(void);
void Time_change_Inc(void);

extern int currentPosition;
extern unsigned int  Alarm_counter;
extern int Alarm_digits[4];
extern unsigned int Realtime_counter;
extern int Realtime_Position;