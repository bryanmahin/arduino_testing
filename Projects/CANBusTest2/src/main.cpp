#include <Arduino.h>
#include <SPI.h>
#include <mcp2515.h>

const int SPI_CS_PIN = 17;
const int CAN_INT_PIN = 2;

const uint32_t CAN_ID_DOOR_STATUS = 0x0809;
const uint8_t SLIDING_DOOR_BYTE_INDEX = 6;

const uint8_t SLIDING_DOOR_OPEN = 1;
const uint8_t SLIDING_DOOR_CLOSED = 0;

MCP2515 mcp2515(SPI_CS_PIN);

void setup() {
  Serial.begin(115200);
  while (!Serial) {};

  SPI.begin();
  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_16MHZ);
  mcp2515.setNormalMode();

  pinMode(CAN_INT_PIN, INPUT);
}

void loop() {
  if (digitalRead(CAN_INT_PIN) == LOW) {
    CANMSG msg;
    mcp2515.readMessage(&msg);

    if (msg.can_id == CAN_ID_DOOR_STATUS) {
      uint8_t sliding_door_state = msg.data[SLIDING_DOOR_BYTE_INDEX];

      if (sliding_door_state == SLIDING_DOOR_OPEN) {
        Serial.println("Sliding door is open.");
      } else if (sliding_door_state == SLIDING_DOOR_CLOSED) {
        Serial.println("Sliding door is closed.");
      }
    }
  }
}