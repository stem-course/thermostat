/*
Code by:
M.Hashir and Areej

This is a code that controls a component based on temperature and humidity measured by sensor

Hardware:
- Arduino
- 3 wires
- DHT11 sensor
- Buzzer

Connections:
When perforated side (side with holes) of DHT sensor is towards you, the left most leg is pin 1 and right most leg is pin 4
Connect pin 1 of dht11 to pin 5V of Arduino
Connect pin 2 of dht11 to pin 2 of Arduino
Connect pin 4 of dht11 to pin GND of Arduino

Connect longer leg of buzzer to pin 11 of Arduino
Connect shorter leg of buzzer to GND of Arduino

A built in LED is already connected on pin 13
*/

#include <dht11.h>                    //Install this library using library manager
int dht_pin= 2;                        //DHT11 is connected to pin 2
int buzzer = 11;
int led = 13;

dht11 DHT;
 
void setup(){
 
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);                                            //donot edit this line
  delay(1000);                                                   //wait for 1 second
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");     //Print this on Serial monitor when program starts
  delay(1000);                                                   //wait for 1 second
 
}           
 
void loop(){
  
    DHT.read(dht_pin);                            //Read Humidity and Temperature value from sensor
    int temperature = DHT.temperature;
    int humidity = DHT.humidity;
    Serial.print("Current humidity = ");           //Print this on Serial monitor
    Serial.print(humidity);                    //Print the value of Humidity on serial monitor
    Serial.print("%  ");                           //donot edit this line
    Serial.print("Temperature = ");                //Print this on Serial monitor
    Serial.print(temperature);                 //Print the value of Temperature on serial monitor
    Serial.println("C  ");                         //donot edit this line
    
    if(temperature<30){         //If temperature is less than 30 degree
    digitalWrite(led,HIGH);          //Turn on LED
    }
    else{                       //Otherwise
    digitalWrite(led,LOW);           //Turn off LED
    }

      if(humidity<40){         //If humidity is less than 40 percent
    digitalWrite(buzzer,HIGH);          //Turn on buzzer
    }
    else{                       //Otherwise
    digitalWrite(buzzer,LOW);           //Turn off buzzer
    }

    delay(5000);                                   //Wait for 5 seconds  
  
}
