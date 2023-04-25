#include <Arduino.h>
#include <SPI.h>
#include <CanHacker.h>
#include <mcp2515_can.h>

// Set SPI CS Pin according to your hardware
const int SPI_CS_PIN = 17;
const int CAN_INT_PIN = 2;

mcp2515_can CAN(SPI_CS_PIN);

CanHacker canHacker(&CAN);

void setup() {
  Serial.begin(115200);
  while (!Serial) {}

  while (CAN_OK != CAN.begin(CAN_500KBPS)) {
    Serial.println(F("CAN init fail, retry..."));
    delay(100);
  }
  Serial.println(F("CAN init ok!"));
  canHacker.begin();
}

void loop() {
  canHacker.tick();
  if (Serial.available()) {
    canHacker.sendSerial(Serial.read());
  }
  if (canHacker.available()) {
    Serial.write(canHacker.recvSerial());
  }
}
