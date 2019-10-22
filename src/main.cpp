#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Wire.h>

#include <BME280I2C.h>

SoftwareSerial hc12(2,3);
BME280I2C bme;

boolean start;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  hc12.begin(9600);  

  Wire.begin();
  bme.begin();

  Serial.println("Hello World");

  hc12.write("AT");
  delay(50);
  int return1 = hc12.read();
  int return2 = hc12.read();

  if (return1 == 79 && return2 == 75)
  {
    start = true;
  }
  
  while (!bme.begin())
  {
    Serial.println("BME280 Non disponible");
  }
  


}

void loop() {
  // put your main code here, to run repeatedly: 
  if (start == 1)
  {
    float temp(NAN), hum(NAN), pres(NAN);

    BME280::TempUnit tempUnit(BME280::TempUnit_Celsius);
    BME280::PresUnit presUnit(BME280::PresUnit_hPa);

    bme.read(pres, temp, hum, tempUnit, presUnit);

    hc12.print("P");
    hc12.print(int(pres*10));
    hc12.print("T");
    hc12.print(int(temp*10));
    hc12.print("H");
    hc12.print(int(hum*10));
    
    Serial.print("P");
    Serial.print(int(pres*10));
    Serial.print("\t T");
    Serial.print(int(temp*10));
    Serial.print("\t H");
    Serial.println(int(hum*10));
  }
  

}