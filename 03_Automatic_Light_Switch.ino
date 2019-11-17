/*
 * Tutorial 2b: Automatic Light Switch
 * 
 * Automatically turns on an LED when it gets dark.
 *
 *
 * To see this sketch in action put the board in a
 * room with little or no sunlight, only lit by your room lights. 
 * Turn the room lights on and off. The LED will automatically
 * turn on when its dark and off when its light.
 *
 * The circuit:
 * - photoresistor from analog in 0 to +5V
 * - 10K resistor from analog in 0 to ground
 * - LED connected to digital pin 2 through a 300ohm resistor
 *
 * Author: Blaise Jarrett
 *
 */

// A constant that describes when its dark enough to
// light the LED. A value close to 600 will light the led
// with less darkness. Play with this number.
const int sensorDark = 55;

int lm35Pin = A0;
int LEDPin = 2;

void setup()
{
    // initialize the LED pin as output
    pinMode(LEDPin, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    int analogValue;
float temperature;
    // read our photocell
    analogValue = analogRead(lm35Pin);
Serial.println(analogValue);
    // The higher the analogValue reading is the darker it is.
    // If its atleast as dark as our constant "sensorDark"
    // light the LED
    if (analogValue > sensorDark)
    {
        digitalWrite(LEDPin, HIGH);
    }
    // Otherwise turn the LED off
    else
    {
        digitalWrite(LEDPin, LOW);
    }

    // wait 1ms for better quality sensor readings
    delay(1);
}
