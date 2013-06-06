#pragma once
  
#include <Arduino.h>

class LedFlasher 
  {
  public:

    // constructor
    LedFlasher (const byte pin, const unsigned long timeOff, const unsigned long timeOn, const bool active = true);
    
    void begin ();
    void update ();
    void on ();
    void off ();
    bool isOn () const;
 
   private:
     const byte pin_;
     const unsigned long timeOff_;
     const unsigned long timeOn_;
     
     bool active_;
     
     unsigned long currentInterval_;  // time till we change state
     unsigned long startTime_;        // when we last changed state
     
  };  // end of LedFlasher class
