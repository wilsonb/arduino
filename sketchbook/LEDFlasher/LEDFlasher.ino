#include <LedFlasher.h>

// set up some LEDs
//LedFlasher floodLight (8, 200, 300);
//LedFlasher shuttleBayDoors (9, 300, 600);
//LedFlasher impulseEngine (10, 900, 100);
LedFlasher strobe (11, 500, 75);
LedFlasher navigation (12, 1000, 1000);
//LedFlasher torpedoes (13, 250, 500);

void setup() 
  {      
  pinMode(3,OUTPUT);
  digitalWrite(3,HIGH);
    //floodLight.begin ();
  //shuttleBayDoors.begin ();
  //impulseEngine.begin ();
  strobe.begin ();
  navigation.begin ();
  //torpedoes.begin ();
  }  // end of setup

void loop() 
  {
  // update lights
  //floodLight.update ();
  //shuttleBayDoors.update ();
  //impulseEngine.update ();
  strobe.update ();
  navigation.update ();
  //torpedoes.update ();
  
  
  // do other useful stuff here ...

 
  }  // end of loop
