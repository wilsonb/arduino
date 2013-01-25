/*
  Seven Segment Display Library Example
  
  Library works with SN74HC595 Shift Registers
  driving a specified number of Seven Segment
  Displays.  Default value is 4.
  
  Suggested pinout is in SevenSeg.h
  
  Created by Brian Wilson November 2012

*/

#include <SevenSeg.h>

#define BUTTON 7  //button input pin

int val1=0;         // val will be used to store the button on/off state
int old_val=0;     // stores previous val
int state=0;       // stores switch on/off state

int roll;          // random number

SevenSeg seven; //Initialize library
int output[4] = { 10,10,10,10 }; //10 makes display blank
void setup() {
  //Setup of Seven Segment Displays is in the Library files
  pinMode(BUTTON, INPUT);  //Button is an input
  //run boot up sequence
  // Counts each digit to 9 and increases the digit to the left 
  for (int i1 = 0; i1 < 10; i1++) {  
          loaderanimation();       
    } 
  
}

void loop() {
  randomSeed(analogRead(0));
  state = 0;
  val1 = digitalRead(BUTTON);  //read input value and store it.
  if((val1==HIGH) && (old_val == LOW)){
    state = 1 - state;
    delay(10); 
  }
  
  old_val = val1;  // store previous button value
  
  if (state == 1) {
    //run roll sequence
    roll = random(1,7);
    output[0] = roll;
    loaderanimation();
    loaderanimation();
    loaderanimation();
    delay(100);
    seven.sevenSegWrite(output);  //display roll number
    delay(1000);  // 10 second delay
  } else {
    output[0] = 10;
    seven.sevenSegWrite(output); //dim display
  }    
}


void loaderanimation() {
  int load[4] = { 0,0,0,0 };
  for (int i = 0; i<6; i++){
    load[0] = i;
    seven.loading(load);
    delay(50);
  }
}

