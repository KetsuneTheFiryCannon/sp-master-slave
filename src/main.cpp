#include <Arduino.h>
#include <Wire.h>

int x = 1;

void setup()
{
  Wire.begin();
  pinMode(2, INPUT);
  Serial.begin(9600);
}
void loop()
{

  if (!digitalRead(2))
  {
    Wire.beginTransmission(0x30);
    Wire.write(x);
    if (x == 1)
      x = 0;
    else
      x = 1;
    Serial.println(x);
    Wire.endTransmission();
  }
}