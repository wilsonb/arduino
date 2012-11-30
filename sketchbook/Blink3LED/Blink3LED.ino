/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led1 = 3;
int led2 = 4;
int led3 = 5;
#define onSwitch 6
//#define offSwitch 7
int val = 0;
int old_val = 0;
int state = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);   
  pinMode(led3, OUTPUT); 
  pinMode(onSwitch, INPUT);
  //pinMode(offSwitch, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  
  val = digitalRead(onSwitch);
  if ((val==HIGH) && (old_val == LOW)) {
    state=1-state;
    delay(25);
  }
  
  old_val = val;
  
  if (state==1){
    BlinkLoop();
  } else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
}
  
void BlinkLoop() {
  digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);               // wait for a second
  digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
  delay(50);               // wait for a second
  digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(25);               // wait for a second
  digitalWrite(led2, LOW);    // turn the LED off by making the voltage LOW
  delay(25);               // wait for a second
  digitalWrite(led3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);               // wait for a second
  digitalWrite(led3, LOW);    // turn the LED off by making the voltage LOW
  delay(50);               // wait for a second
}
