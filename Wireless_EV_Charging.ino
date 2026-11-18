/*
  ==========================================================================
  Project  : Dynamic Wireless EV Charging Track
  File     : Wireless_EV_Charging.ino
  Board    : Arduino Uno / Nano (ATmega328P)
  ==========================================================================

  DESCRIPTION
  -----------
  This sketch controls three transmitter coil sets placed along a track.
  Three IR sensors detect the position of the car (chassis) on the track.
  Each IR sensor is linked to one coil set.

  WORKING PRINCIPLE
  -----------------
  1. At start-up, all three coil sets are switched ON.
  2. The IR sensor output is active LOW (LOW = object detected).
  3. When a sensor detects the car, its linked coil set is switched OFF.
  4. When the car moves away, the coil set is switched ON again.
  5. A small delay of 50 ms is added in the loop for stable readings.

  PIN CONNECTIONS
  ---------------
  IR Sensor 1  -> Digital Pin 2   (controls Coil Set 1)
  IR Sensor 2  -> Digital Pin 3   (controls Coil Set 2)
  IR Sensor 3  -> Digital Pin 4   (controls Coil Set 3)

  Coil Set 1   -> Digital Pin 8
  Coil Set 2   -> Digital Pin 9
  Coil Set 3   -> Digital Pin 10

  HARDWARE NOTES
  --------------
  - Do not drive the coils directly from the Arduino pins.
    Use a MOSFET or relay module for each coil set.
  - Add a flyback diode across each coil.
  - Connect the GND of the Arduino, sensors and coil driver together.
  - Power the IR sensor modules from the 5V pin of the Arduino.

  LOGIC SUMMARY
  -------------
  Sensor LOW  (car detected)  -> Coil output LOW  (coil OFF)
  Sensor HIGH (no car)        -> Coil output HIGH (coil ON)
  ==========================================================================
*/

// IR sensor inputs
const int irSensor1 = 2;
const int irSensor2 = 3;
const int irSensor3 = 4;

// Coil output pins
const int coilSet1 = 8;
const int coilSet2 = 9;
const int coilSet3 = 10;

void setup() {
  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);
  pinMode(irSensor3, INPUT);

  pinMode(coilSet1, OUTPUT);
  pinMode(coilSet2, OUTPUT);
  pinMode(coilSet3, OUTPUT);

  digitalWrite(coilSet1, HIGH);
  digitalWrite(coilSet2, HIGH);
  digitalWrite(coilSet3, HIGH);
}

void loop() {
  int sensor1 = digitalRead(irSensor1);
  int sensor2 = digitalRead(irSensor2);
  int sensor3 = digitalRead(irSensor3);

  digitalWrite(coilSet1, sensor1 == LOW ? LOW : HIGH);
  digitalWrite(coilSet2, sensor2 == LOW ? LOW : HIGH);
  digitalWrite(coilSet3, sensor3 == LOW ? LOW : HIGH);

  delay(50);
}
