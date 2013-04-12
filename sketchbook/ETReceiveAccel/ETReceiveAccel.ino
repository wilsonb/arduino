#include "oscilloscope.h"
#include <EasyTransfer.h>

//create object
EasyTransfer ET; 

struct RECEIVE_DATA_STRUCTURE{
  //put your variable definitions here for the data you want to receive
  //THIS MUST BE EXACTLY THE SAME ON THE OTHER ARDUINO
  float accelG[3];
};

float val[3];
byte lb;
byte hb;
int value;
//give a name to the group of data
RECEIVE_DATA_STRUCTURE mydata;

void setup(){
  Serial.begin(115200);
  //start the library, pass in the data details and the name of the serial port. Can be Serial, Serial1, Serial2, etc. 
  ET.begin(details(mydata), &Serial);
  //define handler function on receiving data
  for (int i=2;i<14;i++){
    pinMode(i, INPUT);
  }
  
}

void loop() {
  //check and see if a data packet has come in. 
  if(ET.receiveData()){
    //this is how you access the variables. [name of the group].[variable name]
    //since we have data, we will blink it out. 
    for (int i = 0; i < 3; i++){ 
      val[i] = mydata.accelG[i];
//      writeOscilloscope(val[i]);
      
//     Serial.print(val[i]);
//     Serial.print(" ");
    }
  }
  
  value = val[2];
  hb = highByte(value<<3);
  Serial.write(hb|224);
  lb = (lowByte(value))&31;
  Serial.write(lb|96);
  value = val[1];
  hb = highByte(value<<3);
  Serial.write(hb|96);
  lb = (lowByte(value))&31;
  Serial.write(lb|96);
//  Serial.println();
  delay(100);
}


