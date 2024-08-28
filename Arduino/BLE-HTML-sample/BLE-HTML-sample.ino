#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

//Randomly generated UUIDs
#define SERVICE_UUID        "b6cc2cb5-1891-4e03-8c7b-eb09cd3db7b6"
#define CHARACTERISTIC_UUID "6a3a4a27-1db1-4309-ab31-8bd1648b91ff"

const char* htmlContent = "<html><body><h1>Hello from ESP32</h1></body></html>";

BLECharacteristic* pCharacteristic;

void setup() {
  BLEDevice::init("ESP32_BLE_HTML");
  
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);

  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ |
                      BLECharacteristic::PROPERTY_NOTIFY
                    );
  pCharacteristic->addDescriptor(new BLE2902());
  pCharacteristic->setValue((uint8_t*)htmlContent, strlen(htmlContent));

  //Starts BLE service
  pService->start();

  //Advertising makes the device discoverable
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->start();
}

void loop() {

}