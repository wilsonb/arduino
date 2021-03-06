/*
  Step28BYJ48.h - Library for Controlling Stepper Motor 28BYJ-48 with
  a ULN2003A driver chip.

  The 28BYJ-48 motor is a 4-phase, 8-beat motor, geared down by
  a factor of 68. One bipolar winding is on motor pins 1 & 3 and
  the other on motor pins 2 & 4. The step angle is 5.625/64 and the 
  operating Frequency is 100pps. Current draw is 92mA. 
  
  Code based on example provided by 4tronix
  http://www.4tronix.co.uk/arduino/Stepper-Motors.php

  Created by Brian Wilson, May 16, 2013.
    
  28BYJ-48 has the following wiring configuration:

  1. Blue Wire - Control Pin 1		1 ----|
  2. Pink Wire - Control Pin 2		   5V-|   M
  3. Yellow Wire - Control Pin 3	3 ----| _____
  4. Orange Wire - Control Pin 4	       |  |  |
  5. Red Wire - 5-12 VDC		       2 5V  4	

  Each stepper motor is connected to a ULN2003A chip with the following
  pinout:
	     ___
	 IN1|   |OUT1 - Blue
	 IN2|   |OUT2 - Pink
	 IN3|   |OUT3 - Yellow
	 IN4|   |OUT4 - Orange
	    |   |                         
	    |   |                           
	    |   |            
	 GND|___|VCC                                                     


*/

#ifndef Step28BYJ48_h
#define Step28BYJ48_h

#include "Arduino.h"

class Step28BY
{
  public:
    Step28BY();
    void clockwise(int degrees); //Turn Clockwise specified degrees rotation
    void counterclockwise(int degrees); //Turn Counterclockwise specified degrees rotation
    
};

#endif
