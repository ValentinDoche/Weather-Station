#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <BME280I2C.h>

SoftwareSerial hc12(2,3);

boolean start;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  hc12.begin(9600);  

  Serial.println("Hello World");

  hc12.write("AT");
  delay(50);
  int return1 = hc12.read();
  int return2 = hc12.read();

  if (return1 == 79 && return2 == 75)
  {
    start = true;
  }
  


}

void loop() {
  // put your main code here, to run repeatedly: 
  if (start == 1)
  {
    /* code */  
  }
  

}