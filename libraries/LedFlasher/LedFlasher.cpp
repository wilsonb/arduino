/*
// Author: Nick Gammon
// Date: 23 December 2012

Usage:

  LedFlasher ledName (pin, offtime, ontime, initiallyactive);   // set parameters
  
  eg.
  
  LedFlasher laserTurrent (5, 1000, 2000, true);   // set parameters. pin 5, off for 1000 mS, on for 2000 mS, initially active
  
  laserTurrent.begin ();    // initialize
  laserTurrent.on ();       // turn on
  laserTurrent.off ();      // turn off
  bool isOn = laserTurrent.isOn ();  // is it currently on?
  
  laserTurrent.update ();   // call in loop function
  
  
    EXAMPLE CODE
    
    
      #include <LedFlasher.h>

      // set up some LEDs
      LedFlasher floodLight (8, 200, 300);
      LedFlasher shuttleBayDoors (9, 300, 600);
      LedFlasher impuleEngine (10, 900, 100);
      LedFlasher strobe (11, 500, 1000);
      LedFlasher navigation (12, 1000, 2000);
      LedFlasher torpedoes (13, 250, 500);
      
      void setup() 
        {      
        floodLight.begin ();
        shuttleBayDoors.begin ();
        impuleEngine.begin ();
        strobe.begin ();
        navigation.begin ();
        torpedoes.begin ();
        }  // end of setup
      
      void loop() 
        {
        // update lights
        floodLight.update ();
        shuttleBayDoors.update ();
        impuleEngine.update ();
        strobe.update ();
        navigation.update ();
        torpedoes.update ();
        
        
        // do other useful stuff here ...
      
       
        }  // end of loop

*/
  
#include <LedFlasher.h>

// constructor
LedFlasher::LedFlasher (const byte pin, const unsigned long timeOff, const unsigned long timeOn, const bool active) :
                   pin_ (pin), timeOff_ (timeOff), timeOn_ (timeOn)
   {
   currentInterval_ = timeOff_;
   startTime_ = 0;
   active_ = active;
   }  // end of LedFlasher::LedFlasher

// set pin to output, get current time
void LedFlasher::begin ()
  {
  pinMode (pin_, OUTPUT);
  digitalWrite (pin_, LOW);
  startTime_ = millis ();  
  }  // end of LedFlasher::begin
  
// call from loop to flash the LED
void LedFlasher::update ()
  {
  // do nothing if not active
  if (!active_)
    return;
    
  unsigned long now = millis ();
  // if time to do something, do it
  if (now - startTime_ >= currentInterval_)
    {
    if (digitalRead (pin_) == LOW)
      {
      digitalWrite(pin_, HIGH);
      currentInterval_ = timeOn_;  
      }
    else
      {
      digitalWrite(pin_, LOW);
      currentInterval_ = timeOff_;  
      }
    startTime_ = now;  
    } // end of if
  
  } // end of LedFlasher::update
 
 // activate this LED
 void LedFlasher::on ()
   {
   active_ = true;
   startTime_ = millis ();  
   currentInterval_ = timeOff_;
   }  // end of LedFlasher::on

 // deactivate this LED
 void LedFlasher::off ()
   {
   active_ = false;
   digitalWrite(pin_, LOW);
   }  // end of LedFlasher::off
   
 // is it active?
 bool LedFlasher::isOn () const
   {
   return active_;
   }  // end of LedFlasher::isOn
 
