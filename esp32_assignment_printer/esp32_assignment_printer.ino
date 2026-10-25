#include "wifi.hpp"
#include "bluetooth.hpp"

// not uploading my WiFi credentials to GitHub
const char* SSID = ; // fill in SSID string
const char* PASS = ; // fill in PASS string
 
// im fine with uploading my printer's MAC to github
uint8_t MAC[] = {0x6D, 0xC8, 0x0A, 0x6C, 0xCD, 0xB9};

void setup() {
  Serial.begin(115200);

  if (initWifi(SSID, PASS) != 0) {
    // idk do something with error handling or like an LED or something
  }
}

void loop() {
  // nothing is gonna happen here because I only want stuff to run once
}

