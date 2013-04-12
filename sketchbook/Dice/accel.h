//Accelerometer Initialization
/* MMA8452Q Example Code
 by: Jim Lindblom
 SparkFun Electronics
 date: November 17, 2011
 license: Beerware - Use this code however you'd like. If you 
 find it useful you can buy me a beer some time.
 
 This code should provide example usage for most features of
 the MMA8452Q 3-axis, I2C accelerometer. In the loop function
 the accelerometer interrupt outputs will be polled, and either
 the x/y/z accel data will be output, or single/double-taps,
 portrait/landscape changes will be announced to the serial port.
 Feel free to comment/uncomment out some of the Serial.print 
 lines so you can see the information you're most intereseted in.
 
 The skeleton is here, feel free to cut/paste what code you need.
 Play around with the settings in initMMA8452Q. Try running the
 code without printing the accel values, to really appreciate
 the single/double-tap and portrait landscape functions. The
 P/L stuff is really neat, something not many accelerometers have.
 
 Hardware setup:
 MMA8452 Breakout ------------ Arduino
 3.3V --------------------- 3.3V
 SDA ----------------------- A4
 SCL ----------------------- A5
 INT2 ---------------------- D3
 INT1 ---------------------- D2
 GND ---------------------- GND
 
 SDA and SCL should have external pull-up resistors (to 3.3V).
 10k resistors worked for me. They should be on the breakout
 board.
 
 Note: The MMA8452 is an I2C sensor, however this code does
 not make use of the Arduino Wire library. Because the sensor
 is not 5V tolerant, we can't use the internal pull-ups used
 by the Wire library. Instead use the included i2c.h, defs.h and types.h files.
*/

#ifndef accel_h
#define accel_h

//#ifdef __cplusplus
//extern "C" {
//#endif

#include <Arduino.h>

void accelsetup(int int1, int int2, byte SCALE, byte dataRate);
void readAccelData(int * destination);
void tapHandler();
void portraitLandscapeHandler();
void initMMA8452(byte fsr, byte dataRate);
void MMA8452Standby();
void MMA8452Active();
void readRegisters(byte address, int i, byte * dest);
byte readRegister(uint8_t address);
void writeRegister(unsigned char address, unsigned char data);

//#ifdef __cplusplus
//}
//#endif

#endif

