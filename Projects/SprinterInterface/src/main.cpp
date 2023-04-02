#include <Arduino.h>
#include <SPI.h>
#include <mcp_can.h>

// Define CAN-BUS message addresses and masks
const uint16_t sliding_door_addr = 0x3A5;
const uint8_t sliding_door_mask = 0x10;
const uint16_t passenger_door_addr = 0x502;
const uint16_t driver_door_addr = 0x500;
const uint8_t door_event_mask = 0x04;

// Define output pins
const int outputPinDrive = 7;
const int outputPinPark = 8;

// Initialize needed variables
bool vehicleStopped = false; // For the Door Open Trigger feature

MCP_CAN CAN(10);

void setup() {
  Serial.begin(115200);

  // Initialize output pins
  pinMode(outputPinDrive, OUTPUT);
  pinMode(outputPinPark, OUTPUT);

  // Initialize MCP2515 CAN controller
  while (CAN_OK != CAN.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ)) {
    Serial.println("CAN BUS Shield init fail");
    Serial.println(" Init CAN BUS Shield again");
    delay(100);
  }
  Serial.println("CAN BUS Shield init ok!");
}

void loop() {
  unsigned long rxId;
  uint8_t len;
  uint8_t rxBuf[8];

  if (CAN_MSGAVAIL == CAN.checkReceive()) {  // Check for received CAN messages
    CAN.readMsgBuf(&rxId, &len, rxBuf);  // Read the received message

    if (rxId == sliding_door_addr) {
      // Sliding door message

      // Check door state using the mask
      bool doorOpen = !(rxBuf[1] & sliding_door_mask);

      // Implement the Door Open Trigger feature
      if (vehicleStopped && doorOpen) {
        // Trigger door open code here
        Serial.println("Door open triggered!");
      }
    } else if (rxId == driver_door_addr || rxId == passenger_door_addr) {
      // Driver or passenger door message

      // Check for door "event" using the mask
      bool doorEvent = rxBuf[5] & door_event_mask;

      // Implement the Drive/Park Detection feature
      if (doorEvent) {
        // Check the specific door and act accordingly (e.g., set output pins)
        if (rxBuf[4] & 0x10) {
          digitalWrite(outputPinDrive, HIGH);
          digitalWrite(outputPinPark, LOW);
        } else if (rxBuf[4] & 0x80) {
          digitalWrite(outputPinDrive, LOW);
          digitalWrite(outputPinPark, HIGH);
        }
      }
    }
  }
}
