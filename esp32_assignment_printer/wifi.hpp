#ifndef __z_WIFI_HPP
#define __z_WIFI_HPP

#include "WiFi.h"

// returns 0 on success 1 on error
static int initWifi(const char* SSID, const char* PASS) {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(500);

  // WiFi connection
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(SSID, PASS);
    for (int i = 0; i < 10; i++) { // 10 seconds of retries before failure
      if (WiFi.status() == WL_CONNECTED) break;

      delay(1000);
    }

    if (WiFi.status() != WL_CONNECTED) {
      Serial.println(F("Not Connected :("));
      return 1;
    }

    Serial.println(F("Connected!"));
    Serial.print(F("Local IP: "));
    Serial.println(WiFi.localIP());
  }
  
  return 0;
}

#endif /* __z_WIFI_HPP */