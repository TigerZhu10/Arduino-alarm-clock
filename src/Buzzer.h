#include <Arduino.h>
void Buzzer_Init(void);
void Buzzer_on(void);
void Buzzer_off(void);
bool Alarm_triggerd(void);
bool Alarm_resume(void);

extern int Buzzer_pin;