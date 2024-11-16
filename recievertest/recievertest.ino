#include <SoftwareSerial.h>

SoftwareSerial HC12(3, 2); // HC-12 TX on Pin D3, RX on Pin D2

void setup() {
  Serial.begin(9600);
  HC12.begin(9600);
  Serial.println("Receiver ready to receive...");
}

void loop() {
  if (HC12.available()) {
    String received = HC12.readString();
    Serial.print("Received: ");
    Serial.println(received);
  }
}
