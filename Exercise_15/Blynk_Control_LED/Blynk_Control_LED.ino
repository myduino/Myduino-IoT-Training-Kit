#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_DEVICE_NAME "YOUR_DEVICE_NAME"
#define BLYNK_AUTH_TOKEN  "YOUR_AUTH_TOKEN"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

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

BLYNK_WRITE(V3) {
  int value = param.asInt();

  pinMode(D4, OUTPUT);
  digitalWrite(D4, value);
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

}

void loop() {
  Blynk.run();
}
