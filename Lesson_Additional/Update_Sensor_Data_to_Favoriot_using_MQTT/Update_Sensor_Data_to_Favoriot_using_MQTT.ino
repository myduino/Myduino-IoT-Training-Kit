#include <ESP8266WiFi.h>
#include <MQTT.h>
#include <SimpleDHT.h>

int pinDHT11 = D5;
SimpleDHT11 dht11(pinDHT11);

const char ssid[] = "YOUR_SSID";
const char password[] = "YOUR_PASSWORD";
const char deviceDeveloperId[] = "YOUR_DEVICE_DEVELOPER_ID";
const char deviceAccessToken[] = "YOUR_DEVICE_ACCESS_TOKEN";

WiFiClientSecure net;
MQTTClient mqtt(1024);

unsigned long lastMillis = 0;

void connectToWiFi() {
  Serial.print("Connecting to Wi-Fi '" + String(ssid) + "' ...");

  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  
  Serial.println(" connected!");
}

void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);
}

void connectToFavoriotMQTT(){
  Serial.print("Connecting to Favoriot MQTT ...");
  
  mqtt.begin("mqtt.favoriot.com", 8883, net);
  mqtt.onMessage(messageReceived);

  String uniqueString = String(ssid) + String(random(1, 100)) + String(random(100, 1000));
  char uniqueClientID[uniqueString.length() + 1];
  
  uniqueString.toCharArray(uniqueClientID, uniqueString.length() + 1);

  net.setInsecure();
  
  while (!mqtt.connect(uniqueClientID, deviceAccessToken, deviceAccessToken)) {
    Serial.print(".");
    delay(500);
  }

  Serial.println(" connected!");

  mqtt.subscribe(String(deviceAccessToken) + "/v2/streams/status");
}

void setup() {
  Serial.begin(9600);
  Serial.println();

  // STEP 1 - Connect to Wi-Fi router/hotspot
  connectToWiFi();
  connectToFavoriotMQTT();
}

void loop() {
  mqtt.loop();
  delay(10);  // <- fixes some issues with WiFi stability

  if (WiFi.status() != WL_CONNECTED) {
    connectToWiFi();
  }

  if (!mqtt.connected()) {
    connectToFavoriotMQTT();
  }

  // STEP 2 - Data Acquisition
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    return;
  }
  
  Serial.print("Data OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" %RH");

  // publish a message roughly every second.
  if (millis() - lastMillis > 10000) {
    lastMillis = millis();

    // STEP 3 - Favoriot MQTT Publish - Send data to Favoriot data stream
    String jsonData = "{";
    jsonData += "\"device_developer_id\":\"" + String(deviceDeveloperId) + "\",";
    jsonData += "\"data\": {";
    jsonData += "\"temperature\": " + (String)temperature + ",";
    jsonData += "\"humidity\": " + (String)humidity;
    jsonData += "}";
    jsonData += "}";
    
    mqtt.publish(String(deviceAccessToken) + "/v2/streams", jsonData);    
  }
}
