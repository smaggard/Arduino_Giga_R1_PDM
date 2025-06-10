#include "constants.h"
#include <Arduino_CAN.h>
#include <mbed.h>
#include <rtos.h>
#include <platform/Callback.h>

using namespace rtos;

Thread t1;
Thread t2;
Thread t3;

struct CANReading {
  float value;
};
struct CANReading readings[3];

union ByteFloatUnion {
  uint8_t byteformat[4];  // Assuming float is 4 bytes
  float floatformat;
} val;

void floatToHexArray(float value, unsigned char *hexArray) {
  // Function to convert float values to hex arrays to be sent as a CAN message.
  memcpy(hexArray, &value, sizeof(float));
  std::swap(hexArray[0], hexArray[3]);
  std::swap(hexArray[1], hexArray[2]);
}

void sendCANMsg(float value, uint32_t canId) {
  // Function to send CAN Messages containing the float value provided
  // on the CAN ID provided.
  unsigned char hexArray[4];
  floatToHexArray(value, hexArray);
  CanMsg const msg(CanExtendedId(canId), sizeof(hexArray), hexArray);
  int const rc = CAN.write(msg);
  if (rc <= 0) {
    Serial.println(rc);
    CAN.end();
    CAN.begin(CanBitRate::BR_1000k);
  }
  delay(5);
}

void setup() {
  // Setup Serials.
  Serial.begin(115200);

  // Set CAN frequency to 1Mbit/s
  if (!CAN.begin(CanBitRate::BR_1000k)) {
    Serial.println("CAN.begin(...) failed.");
    for (;;) {}
  }

  // Setup input and output pins
  for (byte i = 0; i < 16; i = i + 1) {
    // Set input to pullup
    pinMode(inputArray[i], INPUT_PULLUP);
    // Set output to OUTPUT
    pinMode(outputArray[i], OUTPUT);
    // Turnoff output
    digitalWrite(outputArray[i], HIGH);
    readings[0].value = 0.0;
  }

  // Start Threads
  t1.start(mbed::callback(mainLoop));
  t2.start(mbed::callback(receiveLoop));
  t3.start(mbed::callback(readSensors));
}

void loop() {}

void mainLoop(void) {
  while (true) {
    // put your main code here, to run repeatedly:
    // Read inputs and set output per reading.
    for (byte i = 0; i < 16; i = i + 1) {
      if (digitalRead(inputArray[i]) == LOW || readings[i].value == 1) {
        digitalWrite(outputArray[i], LOW);
        sendCANMsg(1, canIDS[i]);
      }
      else {
        digitalWrite(outputArray[i], HIGH);
        sendCANMsg(0, canIDS[i]);
      }
    }
    delay(50);
  }
}

void readSensors(void) {
    // Read sensors
  while (true) {
    for (byte i = 0; i < 8; i = i +1) {
      // Read the Amp sensor
      int sensorValue = analogRead(sensorsArray[i]);
      // Convert it to a 0-5v scale.
      float voltage = sensorValue * (5.0 / 1023.0);
      // Send Can messages
      sendCANMsg(voltage, sensorCanIDS[i]);
    }
    // debounce
    delay(50);
  }
}

void receiveLoop(void) {
  while(true) {
    if (CAN.available()) {
      CanMsg const msg = CAN.read();
      for (byte i = 0; i < 3; ++i) {
        if (msg.getExtendedId() == incomingCanIDS[i]) {
          for (byte i = 0; i < msg.data_length; ++i) {
            val.byteformat[i] = msg.data[i],HEX;
          }
          // Set proper endian
          std::swap(val.byteformat[0], val.byteformat[3]);
          std::swap(val.byteformat[1], val.byteformat[2]);
          // Get the float
          float currentValue = val.floatformat;
          // Set the float in the struct
          readings[i].value = currentValue;
        }
      }
    }
  }
}
                                                                                                                                                    
