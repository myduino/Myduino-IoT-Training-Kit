#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_DEVICE_NAME "YOUR_DEVICE_NAME"
#define BLYNK_AUTH_TOKEN  "YOUR_AUTH_TOKEN"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleDHT.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

unsigned long previousMillis = 0;

int pinDHT11 = D4;
SimpleDHT11 dht11(pinDHT11);

BLYNK_WRITE(V0) {
  int value = param.asInt();

  pinMode(D1, OUTPUT);
  digitalWrite(D1, value);
}

BLYNK_WRITE(V1) {
  int value = param.asInt();

  pinMode(D2, OUTPUT);
  digitalWrite(D2, value);
}

BLYNK_WRITE(V2) {
  int value = param.asInt();

  pinMode(D3, OUTPUT);
  digitalWrite(D3, value);
}

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

  Serial.println("Humidity: " + String(humidity) + " %RH");
  Serial.println("Temperature: " + String(temperature) + " °C");

  if (millis() - previousMillis > 1500){
    previousMillis = millis ();

    Blynk.virtualWrite(V3, int(humidity));
    Blynk.virtualWrite(V4, int(temperature));
  }
}
