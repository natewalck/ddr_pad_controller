/*
  Arduino DDR Pad Controller
  Pin 2 = 97 (Keypad 9 - Up Right)
  Pin 3 = 95 (Keypad 7 - Up Left)
  Pin 4 = 79 (Right Arrow)
  Pin 5 = 80 (Left Arrow)
  Pin 6 = 81 (Down Arrow)
  Pin 7 = 82 (Up Arrow)
  Pin 8 = 88 (Enter)
  Pin 9 = 41 (Escape)
*/

#include "Bounce2.h"

uint8_t buf[8] = { 
  0 };  /* Keyboard report buffer */

// Setup Pins for the Dance Pad Buttons
#define PIN_UP_RIGHT_ARROW 2
#define PIN_UP_LEFT_ARROW 3
#define PIN_RIGHT_ARROW 4
#define PIN_LEFT_ARROW 5
#define PIN_DOWN_ARROW 6
#define PIN_UP_ARROW 7
#define PIN_START 8
#define PIN_BACK 9

byte up_right_button = 97; // Keypad 9
byte up_left_button = 95;  // Keypad 7
byte right_button = 79;    // Right Arrow
byte left_button = 80;     // Left Arrow
byte down_button = 81;     // Down Arrow
byte up_button = 82;       // Up Arrow
byte start_button = 88;    // Enter
byte back_button = 41;     // Escape

// Create bouncer object for each button
Bounce ur_debouncer = Bounce();
Bounce ul_debouncer = Bounce();
Bounce r_debouncer = Bounce();
Bounce l_debouncer = Bounce();
Bounce d_debouncer = Bounce();
Bounce u_debouncer = Bounce();
Bounce s_debouncer = Bounce();
Bounce b_debouncer = Bounce();

void setup() 
{
  Serial.begin(9600);
  // Set up each pin to monitor input
  pinMode(PIN_UP_RIGHT_ARROW, INPUT);
  pinMode(PIN_UP_LEFT_ARROW, INPUT);
  pinMode(PIN_RIGHT_ARROW, INPUT);
  pinMode(PIN_LEFT_ARROW, INPUT);
  pinMode(PIN_DOWN_ARROW, INPUT);
  pinMode(PIN_UP_ARROW, INPUT);
  pinMode(PIN_START, INPUT);
  pinMode(PIN_BACK, INPUT);

  // enable internal pull-ups
  digitalWrite(PIN_UP_RIGHT_ARROW, HIGH);
  digitalWrite(PIN_UP_LEFT_ARROW, 1);
  digitalWrite(PIN_RIGHT_ARROW, 1);
  digitalWrite(PIN_LEFT_ARROW, 1);
  digitalWrite(PIN_DOWN_ARROW, 1);
  digitalWrite(PIN_UP_ARROW, 1);
  digitalWrite(PIN_START, 1);
  digitalWrite(PIN_BACK, 1);

  // Setup debouncers
  ur_debouncer.attach(PIN_UP_RIGHT_ARROW);
  ur_debouncer.interval(25);
  ul_debouncer.attach(PIN_UP_LEFT_ARROW);
  ul_debouncer.interval(25);
  r_debouncer.attach(PIN_RIGHT_ARROW);
  r_debouncer.interval(25);
  l_debouncer.attach(PIN_LEFT_ARROW);
  l_debouncer.interval(25);
  d_debouncer.attach(PIN_DOWN_ARROW);
  d_debouncer.interval(25);
  u_debouncer.attach(PIN_UP_ARROW);
  u_debouncer.interval(25);
  s_debouncer.attach(PIN_START);
  s_debouncer.interval(25);
  b_debouncer.attach(PIN_BACK);
  b_debouncer.interval(25);
  delay(200);
}

void loop()
{
  // Get state for each button
  boolean stateChangedUpRight = ur_debouncer.update();
  boolean stateChangedUpLeft = ul_debouncer.update();
  boolean stateChangedRight = r_debouncer.update();
  boolean stateChangedLeft = l_debouncer.update();
  boolean stateChangedDown = d_debouncer.update();
  boolean stateChangedUp = u_debouncer.update();
  boolean stateChangedStart = s_debouncer.update();
  boolean stateChangedBack = b_debouncer.update();

  // Check each button state and take action accordingly
  if ( stateChangedUpRight ) {
    boolean LAST_PIN_UP_RIGHT_ARROW = ur_debouncer.read(); 

    if ( LAST_PIN_UP_RIGHT_ARROW == LOW)
    // Button was released
    {
      releaseKey();
    } else {
    // Button was pressed
      pressButton(up_right_button);
    }
  }

  if ( stateChangedUpLeft ) {
    boolean LAST_PIN_UP_LEFT_ARROW = ul_debouncer.read(); 

    if ( LAST_PIN_UP_LEFT_ARROW == HIGH )
    // Button was released
    {
      releaseKey();
    } else {
    // Button was pressed
      pressButton(up_left_button);
    }
  }

  if ( stateChangedRight ) {
    boolean LAST_PIN_RIGHT_ARROW = r_debouncer.read(); 

    if ( LAST_PIN_RIGHT_ARROW == HIGH )
    // Button was released
    {
      releaseKey();
    } else {
    // Button was pressed
      pressButton(right_button);
    }
  }


  if ( stateChangedLeft ) {
    boolean LAST_PIN_LEFT_ARROW = l_debouncer.read(); 

    if ( LAST_PIN_LEFT_ARROW == HIGH )
    // Button was released
    {
      releaseKey();
    } else {
    // Button was pressed
      pressButton(left_button);
    }
  }


  if ( stateChangedDown ) {
    boolean LAST_PIN_DOWN_ARROW = d_debouncer.read(); 

    if ( LAST_PIN_DOWN_ARROW == HIGH )
    // Button was released
    {
      releaseKey();
    } else {
    // Button was pressed
      pressButton(down_button);
    }
  }


  if ( stateChangedUp ) {
    boolean LAST_PIN_UP_ARROW = u_debouncer.read(); 

    if ( LAST_PIN_UP_ARROW == HIGH )
    // Button was released
    {
      releaseKey();
    } else {
    // Button was pressed
      pressButton(up_button);
    }
  }


  if ( stateChangedStart ) {
    boolean LAST_PIN_START = s_debouncer.read(); 

    if ( LAST_PIN_START == HIGH )
    // Button was released
    {
      releaseKey();
    } else {
    // Button was pressed
      pressButton(start_button);
    }
  }


  if ( stateChangedBack) {
    boolean LAST_PIN_BACK = b_debouncer.read(); 

    if ( LAST_PIN_BACK == HIGH)
    // Button was released
    {
      releaseKey();
    } else {
    // Button was pressed
      pressButton(back_button);
    }
  }

}

void pressButton(byte button)
{
  buf[2] = button;     // Set button to press
  Serial.write(buf, 8);   // Send keypress
}


// Release the key
void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Release key  
}