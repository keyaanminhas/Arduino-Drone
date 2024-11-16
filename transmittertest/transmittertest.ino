#include <SoftwareSerial.h>

SoftwareSerial HC12(10, 11); // HC-12 TX on Pin 10, RX on Pin 11

void setup() {
  Serial.begin(9600);
  HC12.begin(9600);
  Serial.println("Sender ready to transmit...");
}

void loop() {
  HC12.println("Hello from Sender");
  Serial.println("Message sent from Sender");
  delay(1000); // Send every second
}
