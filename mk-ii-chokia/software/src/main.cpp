#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

// //
// // BLINK
// //
// void setup()
// {
//   pinMode(LED_BUILTIN, OUTPUT);
// }
// void loop()
// {
//   digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
//   delay(200);                      // wait for a second
//   digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
//   delay(200);                      // wait for a second
// }

// //
// // LCD Test
// //
// U8G2_ST7920_128X64_1_SW_SPI u8g2(
//     U8G2_R0, // rotation
//     PA1,     // Clock "E" enable?
//     PA2,     // Data "R/W" might have this and next wrong way.. but meh
//     PA3,     // CS "RS"
//     PA4      // Reset "RST"
// );
// // Also connect +5v to VCC, BLA
// // and - to GND, PSB, BLK
// void setup(void)
// {
// delay(5000); // ALWAYS delay or it can't be reprogrammed easily. Press reset during build
//   u8g2.begin();
// }
// void loop(void)
// {
//   u8g2.firstPage();
//   do
//   {
//     // https://github.com/olikraus/u8g2/wiki/u8g2reference
//     u8g2.setFont(u8g2_font_ncenB14_tr);
//     u8g2.drawStr(0, 24, "Hello World!");
//     // Can't bleeding get it to output a random string
//     // char alphabet[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
//     // char char_array[] = {""};
//     // char_array[0] = char(random(0, 9));
//     // // strcpy(char_array, alphabet[random(0, 25)].c_str());
//     u8g2.drawStr(40, 50, char_array);
//     u8g2.drawBox(random(0, 100), random(30, 50), 8, 8);
//     // Not amazing, then again I've no idea what the page system is so..
//   } while (u8g2.nextPage());
// }

// //
// // Backlight dimming test
// //
// void setup()
// {
//   Serial.begin(9600);
//   delay(10000); // ALWAYS delay or it can't be reprogrammed easily. Press reset during build
//   pinMode(PA0, OUTPUT);
// }
// float x = 0;
// float pi = 3.141592;
// void loop()
// {
//   // if (x > 255)
//   //   x = 0;
//   // Serial.print(x);
//   // Serial.print(' ');
//   // analogWrite(9, x);
//   // delay(20);
//   // x++;
//   if (x > 4 * pi)
//     x = 0;
//   int y = floor(255 * ((sin(x / 2 - pi / 2)) / 2 + .5));
//   // Serial.print(y);
//   // Serial.print(' ');
//   analogWrite(PA0, y);
//   x += 0.01;
//   delay(5);
// }

// //
// // RECEIVE
// //
// #include <SPI.h>
// #include <LoRa.h>
// void setup()
// {
//   Serial.begin(9600);
//   delay(10000); // for uploading to device
//   Serial.println("\nLoRa Receiver");
//   //          (nss, reset, dio0); (dio0 unused)
//   // LoRa.setPins(10, 9);
//   LoRa.setPins(PB6, PB5); //, PA4);  // only sending..
//   if (!LoRa.begin(433E6)) // 433 is legal in the UK and capable by device. 863-870 otherwise. worried it'll clash though
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
//     Serial.print("' with RSSI "); // Received Signal Strength Indicator (0 is theoretical full strength)
//     Serial.println(LoRa.packetRssi());
//   }
// }

// //
// // SEND
// //
// #include <SPI.h>
// #include <LoRa.h>
// int counter = 0;
// void setup()
// {
//   delay(10000); // for uploading to device
//   Serial.begin(9600);
//   Serial.println("\nLoRa Sender");
//   //          (nss, reset, dio0); (dio0 unused)
//   LoRa.setPins(PB6, PB5); //, PA4);  // only sending..
//   if (!LoRa.begin(433E6)) // 433 is legal in the UK and capable by device. 863-870 otherwise. worried it'll clash though
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
//   LoRa.print("hey from chokia ");
//   LoRa.print(counter);
//   LoRa.endPacket();
//   counter++;
//   delay(1000);
// }

//
// SENDY RECEIVY
//
#include <SPI.h>
#include <LoRa.h>
long counter = 0;
long ticker = 0;
long tickerSnapshot = 0;
void setup()
{
  delay(15000); // for uploading to device
  Serial.begin(9600);
  Serial.println("\nLoRa Receiver");
  //          (nss, reset, dio0); (dio0 unused)
  // LoRa.setPins(PB0, PB1); //, PA4); // only sending..
  LoRa.setPins(PB6, PB5); //, PA4);  // only sending..
  if (!LoRa.begin(433E6)) // 433 is legal in the UK and capable by device. 863-870 otherwise. worried it'll clash though
  {
    Serial.println("Starting LoRa failed!");
    while (1)
      ;
  }
}
void loop()
{
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize)
  {
    // received a packet
    Serial.print("Received: '");
    // read packet
    while (LoRa.available())
    {
      Serial.print((char)LoRa.read());
    }
    // print RSSI of packet
    Serial.print("' with RSSI "); // Received Signal Strength Indicator (0 is theoretical full strength)
    Serial.println(LoRa.packetRssi());
    // delay(10);
  }

  if (ticker > 5000)
  {
    tickerSnapshot = millis();
    Serial.print("Sending: ");
    Serial.println(counter);
    // send packet
    LoRa.beginPacket();
    LoRa.print("Hey from chokia ");
    LoRa.print(counter);
    LoRa.endPacket();
    counter++;
    // delay(10);
  }
  ticker = millis() - tickerSnapshot;
}