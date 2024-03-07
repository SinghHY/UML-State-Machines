#include "lcd.h"
#include "main.h"
#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

 void display_init(void){
  
  lcd.begin(16, 2);              // start the library
  lcd.setCursor(0,0);
  lcd.print("Push the buttons"); // print a simple message
 }

 //////////////////////////helper functions//////////////////////////
void display_time(uint32_t time){
  char buf[7];
  String time_msg;
  
  uint16_t m = time / 60;
  uint8_t s = time % 60;
  sprintf(buf,"%03d:%02d",m,s);
  
  time_msg = (String)buf;
  lcd.setCursor(5, 0);
  lcd.print(time_msg);
}

void display_message(String s,uint8_t c , uint8_t r){
    lcd.setCursor(c, r);
    lcd.print(s);
}

void display_clear(void){
    lcd.clear();
}
