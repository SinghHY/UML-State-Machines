
#include "main.h"

static void display_Init(void);
static void protimer_event_dispatcher(protimer_t *const mobj,event_t const *const e);


static protimer_t protimer;

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd_M(rs, en, d4, d5, d6, d7);

// define some values used by the panel and buttons
int adc_key_in  = 0;
#define btnRIGHT  0
#define BTN_PAD_VALUE_INC_TIME 4
#define BTN_PAD_VALUE_DEC_TIME 2
#define BTN_PAD_VALUE_ABRT     6   //btnLEFT
#define BTN_PAD_VALUE_SP       1  //btnSELECT 
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

  uint8_t  btn_pad_value;
  protimer_user_event_t ue;

  static uint32_t current_time = millis();
  static protimer_tick_event_t te;

 btn_pad_value = read_LCD_buttons();  // read the buttons
 
   //2. make an event 
  if(btn_pad_value){
    if(btn_pad_value == BTN_PAD_VALUE_INC_TIME ){
      ue.super.sig = INC_TIME;
    }else if(btn_pad_value == BTN_PAD_VALUE_DEC_TIME){
      ue.super.sig = DEC_TIME;
    }else if(btn_pad_value == BTN_PAD_VALUE_SP){
      ue.super.sig = START_PAUSE;
    }else if(btn_pad_value == BTN_PAD_VALUE_ABRT){
      ue.super.sig = ABRT;
    }
  }
    //3. send it to event dispatcher
    protimer_event_dispatcher(&protimer, &ue.super);

    //4. dispatch the time tick event for every 100ms
  if(millis() - current_time  >= 100){
    //100ms has passed
    current_time = millis();
    te.super.sig = TIME_TICK;
    if(++te.ss > 10) te.ss = 1;
    protimer_event_dispatcher(&protimer, &te.super);
  }
}



static void protimer_event_dispatcher(protimer_t *const mobj,event_t const *const e)
{

    event_status_t status;
    protimer_state_t source, target;
  
    source = mobj -> active_state;
    status = protimer_state_machine(mobj, e);

      if(status == EVENT_TRANSITION)
      {
        target = mobj -> active_state;
        event_t ee;
        //1. run the exit action for the source state
        ee.sig = EXIT;
        mobj -> active_state = source;
        protimer_state_machine(mobj, &ee);

              //2. run the entry action for the target state
        ee.sig = ENTRY;
        mobj -> active_state = target;
        protimer_state_machine(mobj, &ee);
      }
}

static void display_Init(void)
{
  lcd_M.begin(16, 2);
  lcd_M.clear();
  lcd_M.setCursor(0, 0);
}