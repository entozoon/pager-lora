#include <Arduino.h>

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/Tiny3x3a2pt7b.h>
#include <Fonts/Org_01.h>
#include <Fonts/Picopixel.h>
#include <Fonts/TomThumb.h>
#include <nokia-myke.h>

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
// // SEND
// //
// #include <SPI.h>
// #include <LoRa.h>
// int counter = 0;
// void setup()
// {
//   delay(4000); // for uploading to device
//   Serial.begin(9600);
//   Serial.println("\nLoRa Sender");
// //         (nss, reset, dio0); (dio0 unused)
// //         (D10, D8, D9);
// LoRa.setPins(10, 8);
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
//   LoRa.print("hey from pager ");
//   LoRa.print(counter);
//   LoRa.endPacket();
//   counter++;
//   delay(1000);
// }

// //
// // RECEIVE
// //
// #include <SPI.h>
// #include <LoRa.h>
// void setup()
// {
//   delay(4000); // for uploading to device
//   Serial.begin(9600);
//   Serial.println("\nLoRa Receiver");
//   //          (nss, reset, dio0); (dio0 unused)
//   //          (D10, D8, D9);
//   LoRa.setPins(10, 8);
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

// // TEST VOLTMETER READ
// void setup()
// {
//   Serial.begin(9600);
//   delay(4000);
// }
// void loop()
// {
//   int val = analogRead(A0);
//   Serial.println(val);
//   delay(100);
// }

// //
// // SENDY RECEIVY (MEAT)
// //
// #include <SPI.h>
// #include <LoRa.h>
// long counter = 0;
// long ticker = 0;
// long tickerSnapshot = 0;
// void setup()
// {
//   delay(15000); // for uploading to device
//   Serial.begin(9600);
//   Serial.println("\nLoRa Receiver");
//   //          (nss, reset, dio0); (dio0 unused)
//   //          (D10, D8, D9);
//   LoRa.setPins(10, 8);
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
//     Serial.print("Received: '");
//     // read packet
//     while (LoRa.available())
//     {
//       Serial.print((char)LoRa.read());
//     }
//     // print RSSI of packet
//     Serial.print("' with RSSI "); // Received Signal Strength Indicator (0 is theoretical full strength)
//     Serial.println(LoRa.packetRssi());
//     // delay(10);
//   }

//   if (ticker > 10000)
//   {
//     tickerSnapshot = millis();
//     Serial.print("Sending: ");
//     Serial.println(counter);
//     // send packet
//     LoRa.beginPacket();
//     LoRa.print("Hey from pager ");
//     LoRa.print(counter);
//     // dies here! *****
//     LoRa.endPacket();
//     counter++;
//     // delay(1000);
//   }
//   ticker = millis() - tickerSnapshot;
// }
//
//
// LCD Test
//
// Software SPI (slower updates, more flexible pin options):
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
//                                         (clk, din, dc, ce, rst)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 2);
// Hardware SPI (faster, but must use certain hardware pins):
// SCK is LCD serial clock (SCLK) - this is pin 13 on Arduino Uno
// MOSI is LCD DIN - this is pin 11 on an Arduino Uno
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
// Adafruit_PCD8544 display = Adafruit_PCD8544(5, 4, 3);
// Note with hardware SPI MISO and SS pins aren't used but will still be read
// and written to during SPI transfer.  Be careful sharing these pins!
void setup()
{
  delay(5000);
  display.begin();
  display.setContrast(60);
  display.setRotation(2);
  display.setFont(&__nokiafc224pt7b);
  display.setTextColor(BLACK);
  display.setTextSize(1);
}
void loop()
{
  display.clearDisplay();
  display.setCursor(0, 10);
  display.println("3");
  display.println("messages");
  display.println("received");
  display.display();
  delay(1000);
}

// //
// // Backlight dimming test
// //
// // Not quite sure about this.. I heard a 39ohm resistor to gpio could control it. dimming on would be ace
// // but - don't stress too much, if it's just on all the tiem that'd be okay too
// // https://www.algissalys.com/electronics/nokia-5110-lcd-backlight-to-ground-using-gpio
// int pinDim = 3;
// void setup()
// {
//   Serial.begin(9600);
//   delay(5000);
//   // I think D1, D2, are 1, 2.. A0, A1 are A0, A1..
//   pinMode(pinDim, OUTPUT);
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
//   analogWrite(pinDim, y);
//   x += 0.01;
//   delay(5);
// }