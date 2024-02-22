#include <ESP8266WiFi.h>
#include <MQTT.h>
#include <SimpleDHT.h>

#define WIFI_SSID             "YOUR_WIFI_SSID"
#define WIFI_PASSWORD         "YOUR_WIFI_PASSWORD"
#define MQTT_HOST             "broker.hivemq.com"
#define MQTT_PREFIX_TOPIC     "YOUR_PHONE_NUMBER"
#define MQTT_PUBLISH_TOPIC    "/data"
#define MQTT_SUBSCRIBE_TOPIC  "/control"

WiFiClient net;
MQTTClient mqtt;

unsigned long lastMillis = 0;

int pinDHT11 = D5;
SimpleDHT11 dht11(pinDHT11);

void connectToWiFi() {
  Serial.print("Connecting to Wi-Fi '" + String(WIFI_SSID) + "' ...");

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  
  Serial.println(" connected!");
}

void connectToMqttBroker(){
  mqtt.begin("broker.hivemq.com", net);
  mqtt.onMessage(messageReceived);
  
  Serial.print("Connecting to '" + String(MQTT_HOST) + "' ...");
  
  mqtt.begin(MQTT_HOST, net);
  mqtt.onMessage(messageReceived);

  String uniqueString = String(WIFI_SSID) + "-" + String(random(1, 98)) + String(random(99, 999));
  char uniqueClientID[uniqueString.length() + 1];
  
  uniqueString.toCharArray(uniqueClientID, uniqueString.length() + 1);
  
  while (!mqtt.connect(uniqueClientID)) {
    Serial.print(".");
    delay(500);
  }

  Serial.println(" connected!");
  Serial.println("Subscribe to: " + String(MQTT_PREFIX_TOPIC) + String(MQTT_SUBSCRIBE_TOPIC));
  
  mqtt.subscribe(String(MQTT_PREFIX_TOPIC) + String(MQTT_SUBSCRIBE_TOPIC));

}

void messageReceived(String &topic, String &payload) {
  Serial.println("Incoming Data Control: " + payload);

  int commaIndex = payload.indexOf(',');

  String pin = payload.substring(0, commaIndex);
  String value = payload.substring(commaIndex + 1);

  Serial.println("Pin: " + pin);
  Serial.println("Value: " + value);

  pinMode(pin.toInt(), OUTPUT);
  digitalWrite(pin.toInt(), value.toInt());
}

void setup() {
  Serial.begin(115200);
  Serial.println();

  connectToWiFi();
  connectToMqttBroker();

  Serial.println();
}

void loop() {
  mqtt.loop();
  delay(10);  // <- fixes some issues with WiFi stability

  if (WiFi.status() != WL_CONNECTED) {
    connectToWiFi();
  }

  if (!mqtt.connected()) {
    connectToMqttBroker();
  }

  int adc = analogRead(A0);
  float voltage = adc * (3.3 / 1023.00);
  float resistance = (10000 * (3.3 - voltage))/voltage; // Conversion voltage to resistance
  int illuminance = 500 / (resistance / 1000); // Conversion resitance to lumen

  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    return;
  }

  Serial.println("Light: " + String(illuminance));
  Serial.println("Temperature: " + String(temperature));
  Serial.println("Humidity: " + String(humidity));

  if (millis() - lastMillis > 10000) {
    lastMillis = millis();

    String dataInJson = "{";
    dataInJson += "\"humidity\":" + String(humidity) + ",";
    dataInJson += "\"temperature\":" + String(temperature) + ",";
    dataInJson += "\"illuminance\":" + String(illuminance);
    dataInJson += "}";

    Serial.println("Data to Publish: " + dataInJson);
    Serial.println("Length of Data: " + String(dataInJson.length()));
    Serial.println("Publish to: " + String(MQTT_PREFIX_TOPIC) + String(MQTT_PUBLISH_TOPIC));
    
    mqtt.publish(String(MQTT_PREFIX_TOPIC) + String(MQTT_PUBLISH_TOPIC), dataInJson);
  }
}
