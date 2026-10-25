#include "wifi.hpp"
#include "bluetooth.hpp"
#include "indicator_leds.hpp"

#define BUILDING

// not uploading my WiFi credentials to GitHub
const char* SSID = ; // fill in SSID string
const char* PASS = ; // fill in PASS string
 
// im fine with uploading my printer's MAC to github
uint8_t MAC[] = {0x6D, 0xC8, 0x0A, 0x6C, 0xCD, 0xB9};

void setup() {
  Serial.begin(115200);
#ifdef BUILDING
  while (!Serial); // only for while im building it attached to my laptop, otherwise this will hang infinitely
                   // For now, it just prevents garbage in the serial monitor
#endif

  initLeds();

  if (initWifi(SSID, PASS) != 0) {
    blinkWifiLed(); // this takes 10 seconds
    ESP.restart(); // reset the board to try again
  } else {
    wifiLedOn(); // turn it on while wifi is active, turn it off once wifi is not
  }
}

void loop() {
  // nothing is gonna happen here because I only want stuff to run once
}

