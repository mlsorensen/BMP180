#include <Wire.h>
#include <bmp180.h>

BMP180 bsensor;

void setup() {
  // initialize sensor with an oversampling factor (accuracy) of 1 (out of 0-3);
  bsensor.begin(1);
  Serial.begin(9600);
}

void loop() {
  // F is shifted two decimal places to avoid float (centiFahrenheit?) unless needed
  int tempF = bsensor.getFahrenheitHundredths();
  
  // C is shifted one decimal to avoid float
  int tempC  = bsensor.getCelsiusHundredths();
  
  // Pressure is in pascals
  long pressurePascals = bsensor.getPressurePascals();
  
  // Altitude is shifted two decimals to avoid float (centiFeet?) unless needed
  long altitudeFt = bsensor.getAltitudeFeet(pressurePascals);
  
  //centimeters
  long altitudeCm = bsensor.getAltitudeCentimeters(pressurePascals);

  printf("The temperature is %.2f F\n", (float)tempF/100);
  printf("The temperature is %.1f C\n", (float)tempC/10);
  printf("The pressure is %ld Pascals\n", pressurePascals);
  printf("The altitude in feet is %.2f\n", (float)altitudeFt/100);
  printf("The altitude in meters is %.2f\n", (float)altitudeCm/100);
  delay(10000);  
}
