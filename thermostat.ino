/*
  Code by: www.munphurid.com
  M.Hashir

  This is a code for a thermostat
  It turns off or turns on LED when temperature crosses a limit
  This code can also be used for fire alarm by connecting buzzer

  Hardware:
  - Arduino
  - LM35 (Temperature sensor)
  - Buzzer (Optional)

  Connections:
  (When flat side of LM35 faces you with legs downward, leftmost is pin 1)

  Connect pin1 of LM35 to pin 5V of Arduino
  Connect pin2 of LM35 to pin A0 of Arduino
  Connect pin3 of LM35 to pin GND of Arduino
*/

float settemperature = 30.0;                //Set temperature can be changed... device turns on or off at this temperature
int LM35 = A0;                            //LDR is connected to pin A0 of Arduino
int input;          //Will be used later on
float temperature;    //Will be used later on
int device = 13;

void setup() {

  pinMode(LM35, INPUT_PULLUP);   //Donot edit this line
  pinMode(device, OUTPUT);         //Do not edit this line
  Serial.begin(9600);          //Donot edit this line
}


void loop() {

  input = analogRead(LM35);      //Taking input from LM35 Temperature sensor

  temperature = (input / 1024.0) * 500.0;          //Conversion of units

  Serial.print("The temperature in Centrigrade is = ");      //Print this text on screen
  Serial.println(temperature);    //Show the temperature on screen

  if (temperature > settemperature) {
    digitalWrite(device, HIGH);             //If temperature exceeds "settemperature", device is turned on
  }

  else {
    digitalWrite(device, LOW);             //If temperature is below "settemperature", device is turned off
  }

  delay(1000);                    //Wait for sometime before taking the next input



  //now go to the start of void loop()
}
