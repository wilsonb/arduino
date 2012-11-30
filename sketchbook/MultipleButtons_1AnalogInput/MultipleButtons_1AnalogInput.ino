/*
Sketch to show multiple digital inputs on a single Analog Channel

Values valid for 5V input
1 is 700-702
2 is 489-490
3 is 324-325
4 is 172-173

Each switch turns on and off a certain color LED.

*/
//Define LED Pins
int RedLED = 2;
int GreenLED = 3;
int YellowLED = 4;
int BlueLED = 5;

//Initialize LED Activitiy Variables

int Red = 0;
int Green = 0;
int Yellow = 0;
int Blue = 0;


//Define input variable
int SwitchValue = 0;
int SwitchPin = A0;

//Define Debounce variables
int state = 0; //LED state - May not need this
int debounceDelay = 50; //switch delay in ms
int time = 0;
int current_state = 0;
int counter = 0;

void setup() {
  //Declare LED Pins as Output
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(YellowLED, OUTPUT);
  pinMode(BlueLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //Read Analog Pin Value
  if (millis() != time) {
  SwitchValue = analogRead(SwitchPin);
    if (SwitchValue == current_state && counter > 0) {
      counter--;
    }
    if (SwitchValue != current_state) {
      counter++;
    }
    if (counter >= debounceDelay) {
      counter = 0;
      current_state = SwitchValue;
      if (SwitchValue > 0) {
           //Choose which LED to activate
           SwitchAction(SwitchValue);
      }
    }
    time = millis();
  }
  
}

void SwitchAction(int) {

  if (SwitchValue > 700){
     LEDState(Red,RedLED);
     Red = state; 
  } else if (SwitchValue < 700 && SwitchValue > 400){
     LEDState(Green,GreenLED);
     Green = state;
  } else if (SwitchValue < 400 && SwitchValue > 300){
     LEDState(Yellow,YellowLED);
     Yellow = state;
  } else if (SwitchValue > 100 && SwitchValue < 200){
     LEDState(Blue,BlueLED);
     Blue = state;
  }

}

void LEDState (int val, int LEDPin) {
  if (val == 1) {
       digitalWrite(LEDPin, LOW);
       state = 0;
     } else {
       digitalWrite(LEDPin, HIGH);
       state = 1;
     }
  
}  



    
