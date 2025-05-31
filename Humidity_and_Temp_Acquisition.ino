
#include "DHT.h"
#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  
}
void loop() {
  
  // Wait a few seconds between measurements.
  delay(2000);
  
 //********DHT22 Readings********
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
  // Check if any reads failed and exit early (to try again).
  
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  Serial.print(h);
  Serial.print("Hum");
  Serial.print(t); // This is temperature (in °C) reading from Temperature and Humidity sensor (DHT22)
  Serial.print("°C");
  Serial.print(f); // This is temperature (in °F) reading from Temperature and Humidity sensor (DHT22)
  Serial.print("°F");
  Serial.print(hic);
  Serial.print("HIC"); //Meaning Heat index in °C
  Serial.print(hif);
  Serial.println("HIF"); //Meaning Heat index in °F
}
