#include <Arduino.h>
// // BLINK
// void setup()
// {
// pinMode(LED_BUILTIN, OUTPUT);
// }
// void loop()
// {
//   digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
//   delay(200);                      // wait for a second
//   digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
//   delay(200);                      // wait for a second
// }

// // // SEND
// #include <SPI.h>
// #include <LoRa.h>
// int counter = 0;
// void setup()
// {
//   delay(4000); // for uploading to device
//   Serial.begin(115200);
//   Serial.println("\nLoRa Sender");
//   //          (nss, reset, dio0);
//   //          (D8, d3, d1);
//   LoRa.setPins(15, 0, 5);
//   LoRa.if (!LoRa.begin(869E6)) // 863-870 in UK, followed by E6 ? right? for hz, I dunno.
//   {
//     Serial.println("Starting LoRa failed!");
//     while (1)
//       ;
//   }
// }
// void loop()
// {
//   Serial.print("Sending packet: ");
//   Serial.println(counter);
//   // send packet
//   LoRa.beginPacket();
//   LoRa.print("hello ");
//   LoRa.print(counter);
//   LoRa.endPacket();
//   counter++;
//   delay(5000);
// }

// // RECEIVE
// #include <SPI.h>
// #include <LoRa.h>
// void setup()
// {
//   delay(4000); // for uploading to device
//   Serial.begin(115200);
//   Serial.println("\nLoRa Receiver");
//   //          (nss, reset, dio0);
//   //          (D8, d3, d1);
//   LoRa.setPins(15, 0, 5);
//   if (!LoRa.begin(869E6)) // 863-870 in UK, followed by E6 ? right? for hz, I dunno.
//   {
//     Serial.println("Starting LoRa failed!");
//     while (1)
//       ;
//   }
// }
// void loop()
// {
//   // try to parse packet
//   int packetSize = LoRa.parsePacket();
//   if (packetSize)
//   {
//     // received a packet
//     Serial.print("Received packet '");
//     // read packet
//     while (LoRa.available())
//     {
//       Serial.print((char)LoRa.read());
//     }
//     // print RSSI of packet
//     Serial.print("' with RSSI ");
//     Serial.println(LoRa.packetRssi());
//   }
// }

// BLINK
void setup()
{
  Serial.begin(115200);
  delay(4000);
}
void loop()
{
  int val = analogRead(A0);
  Serial.println(val);
  delay(100);
}
