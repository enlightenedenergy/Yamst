typedef enum
{
  LED_OFF_1 = 0,
  LED_ON_1,
  LED_OFF_2,
  LED_ON_2,
  
  NUMBER_OF_LED_STATES
} led_state_e;


#define LED_ON_1_MILLISECONDS   (100)
#define LED_OFF_1_MILLISECONDS  (100)
#define LED_ON_2_MILLISECONDS   (300)
#define LED_OFF_2_MILLISECONDS  (600)

#define LED_PIN LED_BUILTIN
#define switch_led_on()  { digitalWrite(LED_PIN, HIGH); pinMode(LED_PIN, OUTPUT); }
#define switch_led_off() { digitalWrite(LED_PIN, LOW);  pinMode(LED_PIN, OUTPUT); }

void blink_setup()
{
  
}
/* ---------- End of blink_setup ---------- */

void blink_loop()
{
  static led_state_e current_state = LED_OFF_1;            // Starting state
  static led_state_e last_state    = NUMBER_OF_LED_STATES; // Unused state value guarantess a state change on startup.
  static Yamst state_timer; 
  bool   state_has_changed = false;

  if (last_state != current_state)
  {
    // There has been a state change.
    last_state = current_state;
    state_timer.start();
    state_has_changed = true;
  }

  switch(current_state)
  {
    case LED_OFF_1:
      if (state_has_changed)
      {
        switch_led_off();
      }

      if (state_timer.time_has_elapsed(LED_OFF_1_MILLISECONDS))
      {
        current_state = LED_ON_1;
      }
      break;
    
    case LED_ON_1:
      if (state_has_changed)
      {
        switch_led_on();
      }

      if (state_timer.time_has_elapsed(LED_ON_1_MILLISECONDS))
      {
        current_state = LED_OFF_2;
      }
      break;
    
    case LED_OFF_2:
      if (state_has_changed)
      {
        switch_led_off();
      }

      if (state_timer.time_has_elapsed(LED_OFF_2_MILLISECONDS))
      {
        current_state = LED_ON_2;
      }
      break;
    
    case LED_ON_2:
      if (state_has_changed)
      {
        switch_led_on();
      }

      if (state_timer.time_has_elapsed(LED_ON_2_MILLISECONDS))
      {
        current_state = LED_OFF_1;
      }
      break;
    
    default:
      current_state = LED_OFF_1;
      break;
  }
}
/* ---------- End of blink_loop ---------- */
