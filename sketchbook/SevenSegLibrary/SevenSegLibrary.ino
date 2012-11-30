#include <SevenSeg.h>

SevenSeg seven;
int output[4] = { 10,10,10,10 };
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly: 
   
  for (int i1 = 0; i1 < 10; i1++) {
    for (int i2 = 0; i2 < 10; i2++) {
      for (int i3 = 0; i3 < 10; i3++) {
        for (int i4 = 0; i4 < 10; i4++) {

          output[0] = i1;
          output[1] = i2;
          output[2] = i3;
          output[3] = i4;
          seven.sevenSegWrite(output);
          delay(10);
        }
      }
    }
  }
    
  
  
}
