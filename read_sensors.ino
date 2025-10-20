#include "DHTesp.h"
#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

#define DHT_PIN D2
DHTesp dhtSensor;

WiFiClient  client;
char ssid[] = "BKSTAR_T2_02";
char pass[] = "stemstar";

void setup() {
  Serial.begin(115200);
  dhtSensor.setup(DHT_PIN, DHTesp::DHT11);
  WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
  while(WiFi.status() != WL_CONNECTED){
      Serial.print(".");
      delay(500);     
    } 
  Serial.println("\nConnected.");
  ThingSpeak.begin(client);
}

void loop() {
  TempAndHumidity  data = dhtSensor.getTempAndHumidity(); // Read temperature and humidity from the DHT22 sensor

  Serial.println("Temp: " + String(data.temperature, 2) + "°C"); // Print the temperature value with 2 decimal places
  Serial.println("Humidity: " + String(data.humidity, 1) + "%"); // Print the humidity value with 1 decimal place


  ThingSpeak.setField(1, data.temperature);
  ThingSpeak.setField(2, data.humidity);
  int x = ThingSpeak.writeFields(3124663, "F8J09A3QLC36NG0D");
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  delay(20000);  
}
