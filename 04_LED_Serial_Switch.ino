/*
 * Tutorial 3a: LED Serial Switch
 * 
 * Toggle LEDs over serial using the Switch case.
 *
 *
 * To see this sketch in action open the serial monitor
 * and send these characters to toggle the corresponding LED:
 * - r = Red
 * - y = Yellow
 * - g = Green
 * - w = white
 * Send any other character to turn all four LEDs off.
 *
 * The circuit:
 * - 4 LEDs attached to digital pins 2 through 5 with 330ohm resistors
 *
 * Author: Blaise Jarrett
 *
 * modified 2019/10/27
 * by janzeteachesit 
 * Tutorial book: page 35
 * To see this sketch in action open the serial monitor
 * and send these characters to toggle the corresponding LED:
 * - 5 = Red // same as their pins
 * - 4 = Yellow
 * - 3 = Green
 * - 2 = white
 * simulated circuit on tinkercad.com
 * at https://www.tinkercad.com/things/aR6MBQKrhHj
 * shared on create.arduino.cc
 * at https://create.arduino.cc/editor/janzeteachesit_tvbc/f4a40542-51f0-4a0d-87bc-9215bbdc5a8c/preview
 */

// The LEDs are connected to these pins
int LEDRedPin = 5;
int LEDYellowPin = 4;
int LEDGreenPin = 3;
int LEDWhitePin = 2;

void setup()
{
    // set up serial at 9600 baud
    Serial.begin(9600);

    // set all four LED pins to output mode
    pinMode(LEDRedPin, OUTPUT);
    pinMode(LEDYellowPin, OUTPUT);
    pinMode(LEDGreenPin, OUTPUT);
    pinMode(LEDWhitePin, OUTPUT);
}

void toggleLED(int LEDPin)
{
    // toggle the LED on the pin passed as an argument
    digitalWrite(LEDPin, !digitalRead(LEDPin));
}

void loop()
{
    if (Serial.available() > 0)
    {
        // read a single character over serial
        int inByte = Serial.read();

        // do something different for each character
        switch (inByte)
        {
            // if we receive r, y, g, or w
            // toggle the respective LED using our function
            case 'r':
                toggleLED(LEDRedPin);
                break;
            case 'y':
                toggleLED(LEDYellowPin);
                break;
            case 'g':
                toggleLED(LEDGreenPin);
                break;
            case 'w':
                toggleLED(LEDWhitePin);
                break;
            default:
                // if we receive any other character turn all
                // the LEDs off
                digitalWrite(LEDRedPin, LOW);
                digitalWrite(LEDYellowPin, LOW);
                digitalWrite(LEDGreenPin, LOW);
                digitalWrite(LEDWhitePin, LOW);
                break;
        }
    }
}
