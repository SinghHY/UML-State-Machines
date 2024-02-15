
#include "main.h"
#include <LiquidCrystal.h>

static void protimer_event_dispatcher(protimer_t *const mobj, event_t const *const e);
static uint8_t process_button_pad_value(uint8_t btn_pad_value);
static void display_init(void);

/*Main application object */
static protimer_t protimer;

void setup() {
 
   // put your setup code here, to run once:
  Serial.begin(115200);
  display_init();
  Serial.println("Productive timer application");
  Serial.println("===========================");
  pinMode(PIN_BUTTON1,INPUT);
  pinMode(PIN_BUTTON2,INPUT);
  pinMode(PIN_BUTTON3,INPUT);

  protimer_init(&protimer);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello World");
}

static void display_init(void)
{
  begin(16,2);
  clear();
  lcd_move_cursor_L_to_R();
  lcd_set_cursor(0,0);
  lcd_no_auto_scroll();
  lcd_cursor_off();
}

static void protimer_event_dispatcher(protimer_t *const mobj,event_t const *const e)
{

}

static uint8_t process_button_pad_value(uint8_t btn_pad_value)
{

}