#include <Arduino.h>
#include <math.h>

#define pinSensor PA5

//Variabel data
float tegangan; //data untuk tegangan
float ntu;      //data untuk nilai pembacaan satuan sensor kekeruhan
float round_to_dp(float, int);

void setup()
{
  Serial.begin(115200);
  delay(2000);
}

void loop()
{
  tegangan = 00;
  for (int i = 00; i < 800; i++)
  {
    tegangan += ((float)analogRead(pinSensor) / 1023) * 5;
  }
  tegangan = tegangan / 800;
  tegangan = round_to_dp(tegangan, 1);

  if (tegangan < 2.5)
  {
    ntu = 3000;
  }
  else
  {
    ntu = -1120.4 * sq(tegangan) + 5742.3 * tegangan - 4353.8;
  }
  Serial.println("Sensor Turbidity");
  Serial.println(tegangan);
  Serial.println(" V");
  Serial.println(ntu);
  Serial.println(" NTU");
  delay(1000);
}

float round_to_dp(float nilaibaca, int desimal)
{
  float multiplier = powf(10.0f, desimal);
  nilaibaca = roundf(nilaibaca * multiplier) / multiplier;
  return nilaibaca;
}