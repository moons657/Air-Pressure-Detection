//Pressure reading project 
//Keith Mooney 
#include "WSEN_PDUS.h"

Sensor_PDUS sensor;
int LED = 9;
void setup()
{
    pinMode(LED, OUTPUT);
    Serial.begin(9600);

    // Initialize the I2C interface
    sensor.init(PDUS_ADDRESS_I2C);
	
	delay(10);


}
void loop()
{
    float presskPa, tempDeg;
	// Request the temp and pressure data from the sensor
    sensor.getPresAndTemp(pdus2, &presskPa, &tempDeg);
  if(presskPa <-0.50)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }

    // Print the results on the serial monitor
    Serial.print("Pressure is: ");
    Serial.print(presskPa);
    Serial.println("kPa");
    Serial.print("Temperature is: ");
    Serial.print(tempDeg);
    Serial.println("C");
	delay(1000);

  
}
