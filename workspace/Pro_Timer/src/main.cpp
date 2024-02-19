
#include "main.h"


const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd_M(rs, en, d4, d5, d6, d7);

static void display_init(void);
/*Main application object */

// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5
 
// read the buttons
int read_LCD_buttons()
{
 adc_key_in = analogRead(0);      // read the value from the sensor 
 // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
 // we add approx 50 to those values and check to see if we are close
 if (adc_key_in > 1500) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
 if (adc_key_in < 50)   return btnRIGHT;  
 if (adc_key_in < 195)  return btnUP; 
 if (adc_key_in < 380)  return btnDOWN; 
 if (adc_key_in < 500)  return btnLEFT; 
 if (adc_key_in < 700)  return btnSELECT;   
 return btnNONE;  // when all others fail, return this...
}


void setup() {
 
   // put your setup code here, to run once:
  Serial.begin(115200);
  display_init();
  Serial.println("Productive timer application");
  Serial.println("===========================");


}

void loop() {

 lcd_M.setCursor(9,1);           // move cursor to second line "1" and 9 spaces over
 lcd_M.print(millis()/1000);      // display seconds elapsed since power-up
 
 
 lcd_M.setCursor(0,1);            // move to the begining of the second line
 lcd_key = read_LCD_buttons();  // read the buttons
 
 switch (lcd_key)               // depending on which button was pushed, we perform an action
 {
   case btnRIGHT:
     {
     lcd_M.print("RIGHT ");
     break;
     }
   case btnLEFT:
     {
     lcd_M.print("LEFT   ");
     break;
     }
   case btnUP:
     {
     lcd_M.print("UP    ");
     break;
     }
   case btnDOWN:
     {
     lcd_M.print("DOWN  ");
     break;
     }
   case btnSELECT:
     {
     lcd_M.print("SELECT");
     break;
     }
     case btnNONE:
     {
     lcd_M.print("NONE  ");
     break;
     }
 }
}

static void display_init(void)
{

  lcd_M.begin(16, 2);
  lcd_M.clear();
  lcd_M.print("UML State_Machine");
  //lcd_M.setCursor(0, 1);
  //lcd_M.print("UML State_Machine");
}