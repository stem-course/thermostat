
/*
  Code by Wardah Arshad

  This is a code for a thermostat
  It turns off or turns on LED when humidity crosses a limit
  This code can also be used for fire alarm by connecting buzzer

  Hardware:
  - Arduino
  - 3 male to female wires
  - Dht11 module (Can be bought from www.munphurid.com)

  When sensor holes side is facing towards you with legs downward, the left most pin is pin 1.

  Connections for DHT11:
  Connect pin1 of dht11 to pin 5V of Arduino
  Connect pin2 of dht11 to pin A0 of Arduino
  Connect pin4 of dht11 to pin GND of Arduino

  Connections for LED:
  Connect the longer leg of the LED to pin 3 of Arduino
  Connect shorter leg of LED to one leg of a resistor
  Connect the other leg of resistor to GND pin of Arduino
*/

#include <dht11.h>                  //Do not edit
int dht_sensorpin = A0;             //Pin on which DHT sensor is connected
dht11 DHT;                          //Do not edit
int humidity;                       //Do not edit
int temperature;                    //Do not edit
int LED = 3;                        //pin on which Led is connected

void setup() {
  Serial.begin(9600);               //Do not edit... sets speed of communication
  delay(1000);                      //Do not edit
}

void loop() {

  DHT.read(dht_sensorpin);                          //Do not edit this line
  humidity = DHT.humidity;                          //Do not edit this line
  temperature = DHT.temperature;                   //Do not edit this line

  Serial.print("Current humidity = ");            //Do not edit this line
  Serial.print(humidity);                         //Do not edit this line
  Serial.print("%, temperature = ");             //Do not edit this line
  Serial.print(temperature);                     //Do not edit this line
  Serial.println("C  ");                        //Do not edit this line
  delay(5000);                                  //Wait for 5000 milliseconds

  if (humidity > 10) {                        //if humidity is above this value,      (you can change the value)
    pinMode(LED, HIGH);                       // Led light ON...
  }
  else {                                      //otherwise,
    pinMode(LED, LOW);                        // Led light OFF
  }

}
