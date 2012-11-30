/*
  Seven Segment Display Library Example
  
  Library works with SN74HC595 Shift Registers
  driving a specified number of Seven Segment
  Displays.  Default value is 4.
  
  Suggested pinout is in SevenSeg.h
  
  Created by Brian Wilson November 2012

*/

#include <SevenSeg.h>

SevenSeg seven; //Initialize library
int output[4] = { 10,10,10,10 }; //10 makes display blank
void setup() {
  //Setup of Seven Segment Displays is in the Library files
  
}

void loop() {
  // Counts each digit to 9 and increases the digit to the left 
   
  for (int i1 = 0; i1 < 10; i1++) {  
    for (int i2 = 0; i2 < 10; i2++) {
      for (int i3 = 0; i3 < 10; i3++) {
        for (int i4 = 0; i4 < 10; i4++) {

          output[0] = i1; //First Digit
          output[1] = i2; //Second Digit
          output[2] = i3; //Third Digit
          output[3] = i4; // Fourth Digit
          seven.sevenSegWrite(output);
          delay(100); //100 ms delay
        }
      }
    }
  }  
  
}
