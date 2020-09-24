#include <Arduino.h>
#define input PA5

int X;
int Y;
float TIME = 0;
float FREQUENCY = 0;
float WATER = 0;
float TOTAL = 0;
float LS = 0;

void setup()
{
  Serial.begin(115200);
  Serial.print("Water Flow Meter");
  delay(2000);
  pinMode(input, INPUT);
}
void loop()
{
  X = pulseIn(input, HIGH);
  Y = pulseIn(input, LOW);
  TIME = X + Y;
  FREQUENCY = 1000000 / TIME;
  WATER = FREQUENCY / 7.5;
  LS = WATER / 60;
  if (FREQUENCY >= 0)
  {
    if (isinf(FREQUENCY))
    {
      Serial.println("VOL. : 0.00");
      Serial.println("TOTAL : ");
      Serial.print(TOTAL);
      Serial.print(" L");
    }
    else
    {
      TOTAL = TOTAL + LS;
      Serial.println(FREQUENCY);
      Serial.println("VOL. : ");
      Serial.print(WATER);
      Serial.println(" L / M");
      Serial.println("TOTAL : ");
      Serial.print(TOTAL);
      Serial.print(" L");
    }
  }
  delay(1000);
}