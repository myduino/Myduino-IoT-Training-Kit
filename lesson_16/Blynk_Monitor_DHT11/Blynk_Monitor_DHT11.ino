#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleDHT.h>

char auth[] = "m7IgUwXlfiZnAy0ys4RMiBxuk6PFCBA0";
char ssid[] = "myinvententerprise";
char pass[] = "04222682";

unsigned long previousMillis = 0;
int pinDHT11 = D5;
SimpleDHT11 dht11(pinDHT11);
void setup() {
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

}

void loop() {
  Blynk.run();

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >1500){
    previousMillis = millis ();
    byte temperature = 0;
    byte humidity = 0;
    

  dht11.read(&temperature, &humidity, NULL);
  Blynk.virtualWrite (V1, (int)temperature);
  Blynk.virtualWrite (V2, (int)humidity);
  }
}
