/*
  SevenSeg.h - Library for Displaying a pair of seven segment displays
  Created by Brian Wilson, November 23, 2012.
    
  Radio Shack 7 Segment Display with the following common cathode pinout:

  Chip pins:

	  _____       
	1|     |14	1. Anode F		8. Anode C
	2|     |13	2. Anode G		9. Anode RHDP (Decimal)
	 |     |12	4. Common Cathode 	12. Common Cathode
	4|     |	6. Anode E		13. Anode B
	 |     |	7. Anode D		14. Anode A
	6|     |9		
	7|___  |8

  LED Pins
       A _ 
    F |    | B
       G _  
    E |    | C
       D _      . RHDP

  Each display is connected using the SN74HC595N shift register as follows:

	     ___
	   G|   |Vcc
	   E|   |F
	   D|   |Data* 
	   A|   |OE, GND
	   B|   |ST_CP, Latch ---> Arduino
	   C|   |SH_CP, Clock ---> Arduino
	RHDP|   |SRCLR, Vcc
	 GND|___|Serial Out ---> Connected to next shift register Data Pin

  *Data pin of first shift register is connected to Arduino
  Subsequent shift registers connect data pin to Serial Out of 
  previous shift register.

  Latch and Clock pins for all shift registers connect to corresponding Arduino pins

*/

#ifndef SevenSeg_h
#define SevenSeg_h

#include "Arduino.h"

class SevenSeg
{
  public:
    SevenSeg();
    void sevenSegWrite(int display[]); //Write Output
    void blank();	//Make display blank
    void zeroes();	//Display zeroes		 
 // private:
//	int _dataPin;  //74HC595 Data Pin, DS
//	int _clockPin; //74HC595 Clock Pin, SH_CP   
//	int _latchPin;	//74HC595 Latch Pin, ST_CP
//	int _firstdigit; 
//	int _seconddigit;
};

#endif
