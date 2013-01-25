/*
  SevenSeg.cpp - Library for displaying a defined number
  of seven segment displays.  Default is 4.

  Created by Brian Wilson, November 23, 2012.
*/

#include "Arduino.h"
#include "SevenSeg.h"

const int latchPin = 8;
const int clockPin = 12;
const int dataPin = 11;
const int numdisplays = 1;

byte val[numdisplays];


//byte val = B01100000;
//Array to output individual segments

byte loader[6] = {   B00000001,  // = 1
                     B00000100,  // = 6
                     B00001000,  // = 7
		     B01000000,  // = 8                     
		     B00100000,  // = 13
		     B00010000,  // = 14                               
				}; 

//Array to output bytes which light up each digit
byte digits[11] = {  B01111101,  // = 0
                     B01100000,  // = 1
                     B00111110,  // = 2
                     B01111010,  // = 3
                     B01100011,  // = 4
                     B01011011,  // = 5
                     B01011111,  // = 6
                     B01110000,  // = 7
                     B01111111,  // = 8
                     B01110011,  // = 9
		     B00000000   // = Blank                                
				}; 

//Same as digits[][] with the decimal point included
byte dec_digits[11] = {     B11111101,  // = 0
                            B11100000,  // = 1
                            B10111110,  // = 2
                            B11111010,  // = 3
                            B11100011,  // = 4
                            B11011011,  // = 5
                            B11011111,  // = 6
                            B11110000,  // = 7
                            B11111111,  // = 8
                            B11110011,  // = 9
			    B00000000    // = Blank
                                       }; 
SevenSeg::SevenSeg()
{
	
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);
	//_latchPin = latchPin;
	//_clockPin = clockPin;
	//_dataPin = dataPin;

//Initialize Variables

}

void SevenSeg::sevenSegWrite(int display[])
{
//Turn latch pin low to allow shift register to read data	
	digitalWrite(latchPin, LOW);

//Fill val[] array from input array display[]
	for (int i = 0; i < numdisplays; i++) {
		val[i] = digits[display[i]];
		}
//Output val array to shift register(s)
	for (int j = numdisplays-1; j > -1; j--){
		shiftOut(dataPin,clockPin,MSBFIRST, val[j]);
		}		
//Turn latch pin to high to signal end of data stream
	digitalWrite(latchPin, HIGH);


}

void SevenSeg::loading(int display[])
{
//Turn latch pin low to allow shift register to read data	
	digitalWrite(latchPin, LOW);
	
//Fill val[] array from input array display[]
	for (int i = 0; i < numdisplays; i++) {
		val[i] = loader[display[i]];
		}
//Output val array to shift register(s)
	for (int j = numdisplays-1; j > -1; j--){
		shiftOut(dataPin,clockPin,MSBFIRST, val[j]);
		}		
//Turn latch pin to high to signal end of data stream
	digitalWrite(latchPin, HIGH);


}

void SevenSeg::blank()
{
//Turn latch pin low to allow shift register to read data	
	digitalWrite(latchPin, LOW);

//Fill val[] array from input array display[]
	for (int i = 0; i < numdisplays; i++) {
		val[i] = digits[10]; //10 is blank
		shiftOut(dataPin,clockPin,MSBFIRST,val[i]);
		}

//Turn latch pin to high to signal end of data stream
	digitalWrite(latchPin, HIGH);


}

void SevenSeg::zeroes()
{
//Turn latch pin low to allow shift register to read data	
	digitalWrite(latchPin, LOW);

//Fill val[] array from input array display[]
	for (int i = 0; i < numdisplays; i++) {
		val[i] = digits[0]; 
		shiftOut(dataPin,clockPin,MSBFIRST,val[i]);
		}

//Turn latch pin to high to signal end of data stream
	digitalWrite(latchPin, HIGH);


}

