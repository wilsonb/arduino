// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>
#include <SevenSeg.h>

#define TRIGGER_PIN  2  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     3  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
SevenSeg seven;

//int output[4] = {1,2,3,4};
int distance;
byte ones = 0;
byte tens = 0;
byte hundreds = 0;
byte thousands = 0;

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  //seven.sevenSegWrite(output);
}

void loop() {
  //seven.blank();
  delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  distance = uS/US_ROUNDTRIP_IN;
  Serial.print(distance); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.println(" in");
  thousands = distance/1000;
  Serial.println(thousands);
  hundreds = ((distance/100)%10);
  Serial.println(hundreds);
  tens = ((distance/10)%10);
  Serial.println(tens);
  ones = distance%10;
  Serial.println(ones);
  int output[4] = {thousands,hundreds,tens,ones};
  seven.sevenSegWrite(output);
}
