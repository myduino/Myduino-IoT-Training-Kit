#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_DEVICE_NAME "YOUR_DEVICE_NAME"
#define BLYNK_AUTH_TOKEN  "YOUR_AUTH_TOKEN"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleDHT.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YourWiFiName";
char pass[] = "YourWiFiPassword";

unsigned long previousMillis = 0;

int pinDHT11 = D4;
SimpleDHT11 dht11(pinDHT11);

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

}

void loop() {
  Blynk.run();

  byte temperature = 0;
  byte humidity = 0;

  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    // Serial.print("Read DHT11 failed, err="); Serial.print(SimpleDHTErrCode(err));
    // Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  }

  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");

  if (millis() - previousMillis > 1500){
    previousMillis = millis ();

    Blynk.virtualWrite(V2, (int)temperature);
    Blynk.virtualWrite(V3, (int)humidity);
  }
}
