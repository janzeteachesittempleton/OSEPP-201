/*
 * Tutorial 1: Reading Temperature
 * 
 * Read the temperature in celcius over serial.
 *
 * To see this sketch in action open up the serial
 * monitor. Clamp your fingers over the LM35
 * sensor. The temperature will rise and then fall
 * as you remove your fingers.
 *
 * The circuit:
 * - LM35 to 5v, GND, and Vo to analog 0
 *
 * added 20161122 - C. Janze
 * online simulation of circuit and code at:
 * https://www.tinkercad.com/things/50m1Oy1k7uU
 *
 * update 20191026 - C. Janze
 * changed url from Circuits.io (deprecated) to new location at Tinkercad
 * shared on create.arduino.cc
 * at https://create.arduino.cc/editor/janzeteachesit_tvbc/1e34a7a5-c605-42a9-b381-9bac891478bb/preview
 */
 


// the output pin of the LM35 temperature sensor
int lm35Pin = A0;

void setup()
{
    // set up serial at 9600 baud   
    Serial.begin(9600);
}

void loop()
{ 
    int analogValue;
    float temperature;

    // read our temperature sensor
    analogValue = analogRead(lm35Pin);

    // convert the 10bit analog value to celcius
    temperature = float(analogValue) / 1023;
    temperature = temperature * 500;

    // print the temperature over serial
    Serial.print("Temp: ");
    Serial.print(temperature);
    Serial.println("C");
    
    // wait 1s before reading the temperature again
    delay(1000);
}

