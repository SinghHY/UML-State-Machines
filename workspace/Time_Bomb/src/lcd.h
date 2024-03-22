#ifndef LCD_H
#define LCD_H
#include<Arduino.h>


void display_init(void);
void display_time(uint32_t time);
void display_message(String s,uint8_t c , uint8_t r);
void Boom(void);
void display_clear(void);


#endif 