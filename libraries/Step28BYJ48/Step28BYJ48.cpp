/*
  Step28BYJ48.cpp - Library for Controlling Stepper Motor 28BYJ-48 with
  a ULN2003A driver chip.

  Code based on example provided by 4tronix
  http://www.4tronix.co.uk/arduino/Stepper-Motors.php

  Created by Brian Wilson, May 16, 2013.
*/

#include "Arduino.h"
#include "Step28BYJ48.h"


//Define Arduino Pins
const int bluePin = 8;
const int pinkPin = 9;
const int yellowPin = 10;
const int orangePin = 11;

//Define Stepper Motor Constants
const int revs = 512; //Number of steps per full revolution
int motorSpeed = 1200; //stepper motor speed
int steps;  //Number of steps to rotate

/*
  8 phase output order is in the following sequence:

  1. Drive IN4 only		5. Drive IN2 only
  2. Drive IN4 and IN3		6. Drive IN2 and IN1
  3. Drive IN3 only		7. Drive IN1 only
  4. Drive IN3 and IN2		8. Drive IN4 and IN1

*/

//The following bits perform the 8-phase output as shown:
//               1       2       3       4       5       6       7       8 
int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};


Step28BY::Step28BY()
{
	
	pinMode(bluePin, OUTPUT);
	pinMode(pinkPin, OUTPUT);
	pinMode(yellowPin, OUTPUT);
	pinMode(orangePin, OUTPUT);

}

void Step28BY::clockwise(int degrees)
{
//convert degree input to steps
	steps = (degrees/360)*revs; //determine percentage of full revolution
	
	for (int i = 0; i < steps; i++) {
		
		for (int j = 0; j < 8; j++){
			  digitalWrite(bluePin, bitRead(lookup[j], 0));
  			  digitalWrite(pinkPin, bitRead(lookup[j], 1));
  			  digitalWrite(yellowPin, bitRead(lookup[j], 2));
 			  digitalWrite(orangePin, bitRead(lookup[j], 3));
			delayMicroseconds(motorSpeed);
		}
	}

}

void Step28BY::counterclockwise(int degrees)
{
//convert degree input to steps
	steps = (degrees/360)*revs; //determine percentage of full revolution
	
	for (int i = 0; i < steps; i++) {
		
		for (int j = 7; j >= 0; j--){
			digitalWrite(bluePin, bitRead(lookup[j], 0));
  			digitalWrite(pinkPin, bitRead(lookup[j], 1));
  			digitalWrite(yellowPin, bitRead(lookup[j], 2));
 			digitalWrite(orangePin, bitRead(lookup[j], 3));
			delayMicroseconds(motorSpeed);
		}
	}

}


