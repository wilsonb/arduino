/*

Working with the 595 shift register

Shift registers in series push the value down the line.
digit is the first value populated which is moved to 
the second shift register as digit1 is sent to the 
first shift register.

The first digit increases as the second digit finishes
the count from 0 to 9.  A 100 ms delay makes the first 
digit seconds and the second digit 0.1 seconds.

*/

//Pin connected to latch pin (ST_CP) of 74HC595
const int latchPin = 8;
//Pin connected to clock pin (SH_CP) of 74HC595
const int clockPin = 12;
////Pin connected to Data in (DS) of 74HC595
const int dataPin = 11;


byte secondval = B01100000;
byte firstval = B01100000;
int seconddigit = 0; //second digit
int firstdigit = 0; //first digit
byte seven_seg_digits[10][1] = { { B01111101 },  // = 0
                                 { B01100000 },  // = 1
                                 { B00111110 },  // = 2
                                 { B01111010 },  // = 3
                                 { B01100011 },  // = 4
                                 { B01011011 },  // = 5
                                 { B01011111 },  // = 6
                                 { B01110000 },  // = 7
                                 { B01111111 },  // = 8
                                 { B01110011 }   // = 9
                                };

void setup() {
  
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
}

void loop() {
  
    
  for (firstdigit = 0; firstdigit < 10; firstdigit++){
    for (seconddigit = 0 ; seconddigit < 10; seconddigit++) {
      secondval = seven_seg_digits[0][seconddigit];
      firstval = seven_seg_digits[0][firstdigit];
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin,clockPin,MSBFIRST,secondval);
      shiftOut(dataPin,clockPin,MSBFIRST,firstval);
      digitalWrite(latchPin, HIGH);
      delay(1000);
      }
  }
  
}
