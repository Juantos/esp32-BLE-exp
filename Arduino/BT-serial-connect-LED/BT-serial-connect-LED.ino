#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

  /*FLAG*/
  boolean connBTEstablished = false;

void setup() {
  /*SERIAL COMMS*/
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT_Device");

  /*PINOUT*/
  pinMode(12, OUTPUT);  // Set GPIO12 as an output pin
  digitalWrite(12, LOW);  // Ensure GPIO12 is initially off

  Serial.println("The device started, now you can pair it with Bluetooth!");
}

void loop() {
  // Check if a device is connected
  if (SerialBT.hasClient()) {
      if(!connBTEstablished){
        SerialBT.println("LED on");
        Serial.println("LED on");
        digitalWrite(12, HIGH);  // Turn on GPIO12 when a device connects
      }
      connBTEstablished = true;
  } else {
      Serial.println("LED off");
      digitalWrite(12, LOW);  // Turn off GPIO12 when the device disconnects
      connBTEstablished = false;
  }
}