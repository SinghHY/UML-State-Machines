
#include "main.h"

static void display_Init(void);

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd_M(rs, en, d4, d5, d6, d7);

// define some values used by the panel and buttons
int adc_key_in  = 0;
#define btnRIGHT  0
#define BTN_PAD_VALUE_INC_TIME 1
#define BTN_PAD_VALUE_DEC_TIME 2
#define BTN_PAD_VALUE_ABRT     3   //btnLEFT
#define BTN_PAD_VALUE_SP       4  //btnSELECT 
#define btnNONE   5

// read the buttons
int read_LCD_buttons()
{
 adc_key_in = analogRead(0);      // read the value from the sensor 
 // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
 // we add approx 50 to those values and check to see if we are close
 if (adc_key_in > 1500) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
 if (adc_key_in < 50)   return btnRIGHT;  
 if (adc_key_in < 195)  return BTN_PAD_VALUE_INC_TIME ; 
 if (adc_key_in < 380)  return BTN_PAD_VALUE_DEC_TIME; 
 if (adc_key_in < 500)  return BTN_PAD_VALUE_ABRT ; 
 if (adc_key_in < 700)  return BTN_PAD_VALUE_SP;   
 return btnNONE;  // when all others fail, return this...
}

void setup() {

  Serial.begin(115200);
  display_Init();

  Serial.println("Productive timer application");
  Serial.println("===========================");
}

void loop() {
  // put your main code here, to run repeatedly:
}


static void display_Init(void)
{
  lcd_M.begin(16, 2);
  lcd_M.clear();
  lcd_M.print("UML State_Machine");
}