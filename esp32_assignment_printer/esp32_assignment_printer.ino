#include "WiFi.h"

// not uploading my WiFi credentials to GitHub
const char* SSID = ; // fill in SSID string
const char* PASS = ; // fill in PASS string

void setup() {
  Serial.begin(115200);
  while (!Serial);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);
}

void loop() {
  Serial.println("LOOP STARTING");

  // WiFi connection
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(SSID, PASS);
    for (int i = 0; i < 100; i++) {
      if (WiFi.status() == WL_CONNECTED) break;

      delay(1000);
    }

    if (WiFi.status() != WL_CONNECTED) {
      Serial.println("Not Connected :(");
      return;
    }

    Serial.println("Connected!");
    Serial.print("Local IP: ");
    Serial.println(WiFi.localIP());
  }
}

