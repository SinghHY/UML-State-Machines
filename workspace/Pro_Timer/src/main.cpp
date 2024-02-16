
#include "main.h"



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

  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Getting Started");
  lcd.setCursor(0, 1);
  lcd.print("UML State_Machine");
}