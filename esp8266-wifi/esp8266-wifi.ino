#include <ESP8266WiFi.h>    // WiFi

#define WIFI_STA_NAME "realme X7 Pro 5G"
#define WIFI_STA_PASS "15062543"

WiFiClient client;

void setup() {
  Serial.begin(9600);//ปรับตามที่ตั้งค่าใน Device Manager
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WIFI_STA_NAME);

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_STA_NAME, WIFI_STA_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }

  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnectWiFi() {  
    Serial.print("Reconnecting");
    WiFi.mode(WIFI_STA);  
    WiFi.begin(WIFI_STA_NAME, WIFI_STA_PASS);  
    while (WiFi.status() != WL_CONNECTED) {  
        delay(500);  
        Serial.print(".");
    }  
    Serial.println("Connected!");
}  

void loop() {
  if (WiFi.status() != WL_CONNECTED) {  
      reconnectWiFi();  
  }
  delay(3000);
}
