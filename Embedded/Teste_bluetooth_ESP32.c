#include "BluetoothSerial.h"

#define ANALOG_PIN 4
int analog_value = 0;
String texto = "Simulação Bluetooth: ";

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {

  analog_value = analogRead(ANALOG_PIN);
  String bt_value = texto + analog_value;
  SerialBT.println(bt_value);
  Serial.println(bt_value);
  
  delay(500);
}
