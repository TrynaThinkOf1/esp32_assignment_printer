#ifndef __z_INDICATOR_LEDS_HPP
#define __z_INDICATOR_LEDS_HPP

const int WIFI_LED_PIN = 19;
const int BT_LED_PIN = 15;

static void initLeds() {
  pinMode(WIFI_LED_PIN, OUTPUT);
  digitalWrite(WIFI_LED_PIN, LOW);

  pinMode(BT_LED_PIN, OUTPUT);
  digitalWrite(BT_LED_PIN, LOW);
}

static void __ledOn(int pin) {
  digitalWrite(pin, HIGH);
}
static void __ledOff(int pin) {
  digitalWrite(pin, LOW);
}

static void wifiLedOn() {
  __ledOn(WIFI_LED_PIN);
}
static void wifiLedOff() {
  __ledOff(WIFI_LED_PIN);
}
static void btLedOn() {
  __ledOn(BT_LED_PIN);
}
static void btLedOff() {
  __ledOff(BT_LED_PIN);
}

// blinks for 10 seconds then returns
static void __blinkLed(int pin) {
  for (int i = 0; i < 20; i++) {
    __ledOn(pin);
    delay(250);
    __ledOff(pin);
    delay(250);
  }
}

static void blinkWifiLed() {
  __blinkLed(WIFI_LED_PIN);
}
static void blinkBtLed() {
  __blinkLed(BT_LED_PIN);
}


#endif /* __z_INDICATOR_LEDS_HPP */