#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT Final");
  dht.begin();
  

}

void loop() {
  delay(500);

  float h=dht.readHumidity();

  float t=dht.readTemperature();

  float f=dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("failed to read from DHT sensor!"));
    return;
  }

  float hif=dht.computeHeatIndex(f,h);

  float hic=dht.computeHeatIndex(t,h,false);


  Serial.println(t);
  Serial.println(h);

}
