/*
  28BYJ-48 Stepper Library Example
  
  Rotate the motor in one full rotation in each direction	
  
  Created by Brian Wilson May 2013

*/

#include <Step28BYJ48.h>

Step28BY stepper; //Initialize library

void setup() {
  //Setup is in the Library files

}

void loop() {

  stepper.clockwise(360); //Enter desired rotation in degrees (0-360)
  delay(500);
  stepper.counterclockwise(360); //Enter desired rotation in degrees (0-360)
  delay(500);
}
