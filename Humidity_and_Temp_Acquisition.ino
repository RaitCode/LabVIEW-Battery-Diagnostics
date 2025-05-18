//54.00Hum21.20Â°C70.16Â°F20.79HIC69.41HIF
// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"
#define DHTPIN 2     // Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

// Variable definitions and libraries for K_Type Thermocouple
#include "max6675.h"
int thermoSO = 12;
int thermoCS = 5;
int thermoSCK = 8;
float Temperature;

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 3 (on the right) of the sensor to GROUND (if your sensor has 3 pins)
// Connect pin 4 (on the right) of the sensor to GROUND and leave the pin 3 EMPTY (if your sensor has 4 pins)
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);
MAX6675 thermocouple(thermoSCK, thermoCS, thermoSO);
void setup() {
  Serial.begin(9600);
  //Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
  //********Thermocouple Readings********
  Temperature = thermocouple.readCelsius();

 //********DHT11 Readings********
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

  //Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print("Hum");
  //Serial.print(F("%  Temperature: "));
  Serial.print(t); // This is temperature (in °C) reading from Temperature and Humidity sensor (DHT11)
  Serial.print("°C");
  //Serial.print(F("°C "));
  Serial.print(f);
  Serial.print("°F");
  //Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print("HIC"); //Meaning Heat index in °C
  //Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println("HIF"); //Meaning Heat index in °F
  //Serial.println(F("°F"));
  //Serial.print(thermocouple.readCelsius()); // This is Temperature reading (in °C) from the Thermocouple
   //Serial.println("°C"); // 
   //delay(500);
}
