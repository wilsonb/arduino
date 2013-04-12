/*
  Electronic Dice Software
  
  Random number will display on Seven Segment Display depending on
  mode and accelerometer input (roll).
  
  Supported modes are for multiple dice and number of sides ranging
  from 3 to 20.
  
  Created by Brian Wilson February 2013
  
  SevenSeg library to illuminate displays
  Sparfun Advanced Accelerometer Sketch for accelerometer input

*/
#include "display.h"
#include "accel.h"


int accelCount[3];  // Stores the 12-bit signed value
float accelG[3];  // Stores the real accel value in g's

const byte SCALE = 2;  // Sets full-scale range to +/-2, 4, or 8g. Used to calc real g values.
// Set the output data rate below. Value should be between 0 and 7
const byte dataRate = 0;  // 0=800Hz, 1=400, 2=200, 3=100, 4=50, 5=12.5, 6=6.25, 7=1.56
  
  // Pin definitions
int int1Pin = 2;  // These can be changed, 2 and 3 are the Arduinos ext int pins
int int2Pin = 3;

//switch debounce
int val1=0;         // val will be used to store the button on/off state
int old_val=0;     // stores previous val
int state=0;       // stores switch on/off state

int roll;          // random number

//SevenSeg seven; //Initialize library
int output[4] = { 10,10,10,10 }; //10 makes display blank

void setup() {
  Serial.begin(115200);
  //initialize accelerometer
  accelsetup(int1Pin, int2Pin, SCALE, dataRate);
  //initialize shift registers for Seven Segment Display
  initSevenSeg();
  //run boot up sequence
  for (int i1 = 0; i1 < 5; i1++) {  
          loaderanimation();       
    } 
  randomSeed(analogRead(0));

}

void loop() {
  
  //Read accelerometer baseline data
  if (digitalRead(int1Pin)==1) {
      readAccelData(accelCount);
  
    //store data
    for (int i=0; i<3; i++) {
      accelG[i] = (float) accelCount[i]/((1<<12)/(2*SCALE));
    }
  } 
  
  
    
    state = 0;
  //val1 = digitalRead(BUTTON);  //read input value and store it.
  if((val1==HIGH) && (old_val == LOW)){
    state = 1 - state;
    delay(10); 
  }
  
  old_val = val1;  // store previous button value
  
  if (state == 1) {
    //run roll sequence
    roll = random(1,7);
    output[0] = roll;
  for (int i1 = 0; i1 < 3; i1++) {  
          loaderanimation();       
    } 
    delay(100);
    sevenSegWrite(output);  //display roll number
    delay(1000);  // 10 second delay
  } else {
    output[0] = 10;
    sevenSegWrite(output); //dim display
  }    
}


void loaderanimation() {
  int load[4] = { 0,0,0,0 };
  for (int i = 0; i<6; i++){
    load[0] = i;
    loading(load);
    delay(50);
  }
}

