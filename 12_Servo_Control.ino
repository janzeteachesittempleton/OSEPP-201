/*
   Tutorial 6b: Servo Control

   Control the position of your servo using
   a potentiometer.

   The circuit:
   - Servo Brown pin to ground
   - Servo Red pin to 5v
   - Servo Orange pin to digital pin 9
   - Potentiometer connected to 5v, gnd as a voltage divider
   - Potentiometer wiper connected to Analog pin 0

   by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>
   modified 14 August 2013
   by Blaise Jarrett

   This example code is in the public domain.

   Derivative work from:
   http://arduino.cc/en/Tutorial/Knob


    modified 2019/10/30
   by janzeteachesit
   Tutorial book: page 103
   simulated circuit on tinkercad.com
   at https://www.tinkercad.com/things/cLoYBzyUtv4
   shared on create.arduino.cc
   at https://create.arduino.cc/editor/janzeteachesit_tvbc/83d397eb-3b14-495c-8e48-2bb4ab8c60f8/preview

*/

#include <Servo.h>

// the Orange pin is connected to digital pin 9
int servoPin = 9;
// analog pin used to connect the potentiometer
int potPin = A0;

// create servo object to control our servo
// a maximum of eight servo objects can be created
Servo myServo;

void setup()
{
  // attaches the servo on pin 9 to the servo object
  myServo.attach(servoPin);
}

void loop()
{
  int analogValue;
  int position;

  // reads the value of the potentiometer (value between 0 and 1023)
  analogValue = analogRead(potPin);

  // scale it to use it with the servo (value between 0 and 180)
  position = map(analogValue, 0, 1023, 0, 179);

  // sets the servo position according to the scaled value
  myServo.write(position);

  // waits for the servo to get there
  delay(15);
}
