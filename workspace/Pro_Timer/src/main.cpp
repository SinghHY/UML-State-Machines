
#include "main.h"


const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd_M(rs, en, d4, d5, d6, d7);

static void display_init(void);
/*Main application object */

void setup() {
 
   // put your setup code here, to run once:
  Serial.begin(115200);
  display_init();
  Serial.println("Productive timer application");
  Serial.println("===========================");


}

void loop() {

  Serial.println("Hello World");
}

static void display_init(void)
{

  lcd_M.begin(16, 2);
  lcd_M.clear();
  lcd_M.print("Getting Started");
  lcd_M.setCursor(0, 1);
  lcd_M.print("UML State_Machine");
}