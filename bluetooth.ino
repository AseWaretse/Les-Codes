
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3);                                // RX, TX pins for Bluetooth module
void setup() {
  bluetooth.begin(9600);                                       // Bluetooth module baud rate  

}

void loop() {
 if(bluetooth.available())
  {
    char data = bluetooth.read();
    Serial.print("Received data: ");
    Serial.println(data);
  }
}
