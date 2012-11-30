#include <SevenSeg.h>

SevenSeg seven; 
int count1 = 0; //first digit counter
int count2 = 0; //second digit counter
void setup() {
  // No setup required

}

void loop() {
  // Count from 0 to 99 every 100 ms 
  for (count1 = 0; count1<10;count1++){
    for (count2 = 0; count2<10;count2++){
      seven.sevenSegWrite(count1,count2);
      delay(100);
    }
    
  }
  
}
