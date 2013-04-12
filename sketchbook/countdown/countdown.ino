// Date and time functions using a DS1307 RTC connected via I2C and Wire lib

#include <Wire.h>
#include "RTClib.h"
#include <SevenSeg.h>

SevenSeg seven;
RTC_DS1307 RTC;
int currentyear;
int unchangedyear;
int currentmonth;
int currentday;
long currentval;
long christmasday;
long diff;
int digit[2] = { 10, 10 };


void setup () {
    Serial.begin(57600);
    Wire.begin();
    RTC.begin();

  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    //RTC.adjust(DateTime(__DATE__, __TIME__));
  }
    for (int i1 = 0; i1 < 5; i1++) {  
          loaderanimation();       
    } 
}

void loop () {
    DateTime now = RTC.now();
    currentyear = now.year();
    unchangedyear = currentyear;
    currentmonth = now.month();
    currentday = now.day();
    if ((currentmonth == 1) || (currentmonth == 2)) {
        currentmonth = currentmonth + 12;
        currentyear = currentyear - 1;
    }
    
    currentval = 365*currentyear + currentyear/4 - currentyear/100 + currentyear/400 + currentday + (153*currentmonth+8)/5;
    christmasday = 365*unchangedyear + unchangedyear/4 - unchangedyear/100 + currentyear/400 + 25 + (153*12 + 8)/5;
    diff = christmasday - currentval;
    digit[0] = (diff/10)%10;
    digit[1] = diff%10;
    seven.sevenSegWrite(digit);
    delay(3000);
}

void loaderanimation() {
  int load[2] = { 0,0 };
  for (int i = 0; i<6; i++){
    load[0] = i;
    load[1] = i;
    seven.loading(load);
    delay(50);
  }
}


  
  
