#include <Arduino.h>

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

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

// // SEND
// #include <SPI.h>
// #include <LoRa.h>
// int counter = 0;
// void setup()
// {
//   delay(4000); // for uploading to device
//   Serial.begin(115200);
//   Serial.println("\nLoRa Sender");
// //          (nss, reset, dio0); (dio0 unused)
// //          (D8, D0);
// LoRa.setPins(15, 16);
//   if (!LoRa.begin(433E6))  // 433 is legal in the UK and capable by device. 863-870 otherwise. worried it'll clash though
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
//   delay(1000);
// }

// // RECEIVE
// #include <SPI.h>
// #include <LoRa.h>
// void setup()
// {
//   delay(4000); // for uploading to device
//   Serial.begin(115200);
//   Serial.println("\nLoRa Receiver");
//   //          (nss, reset, dio0); (dio0 unused)
//   //          (D8, D0);
//   // LoRa.setPins(15, 16);
//   //          (D8, D0);
//   LoRa.setPins(10, 9);
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
//   Serial.begin(115200);
//   delay(4000);
// }
// void loop()
// {
//   int val = analogRead(A0);
//   Serial.println(val);
//   delay(100);
// }

// // SENDY RECEIVY NANO
// #include <SPI.h>
// #include <LoRa.h>
// long counter = 0;
// long ticker = 0;
// long tickerSnapshot = 0;
// void setup()
// {
//   delay(4000); // for uploading to device
//   Serial.begin(115200);
//   Serial.println("\nLoRa Receiver");
//   //          (nss, reset, dio0); (dio0 unused)
//   // LoRa.setPins(15, 16); // Wemos (D8, D0)
//   LoRa.setPins(10, 9);    //  Nano (D8, D0)
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

//   if (ticker > 5000)
//   {
//     tickerSnapshot = millis();
//     Serial.print("Sending packet: ");
//     Serial.println(counter);
//     // send packet
//     LoRa.beginPacket();
//     LoRa.print("hello ");
//     LoRa.print(counter);
//     LoRa.endPacket();
//     counter++;
//   }
//   ticker = millis() - tickerSnapshot;
// }

// // LCD Test
// // Software SPI (slower updates, more flexible pin options):
// // pin 7 - Serial clock out (SCLK)
// // pin 6 - Serial data out (DIN)
// // pin 5 - Data/Command select (D/C)
// // pin 4 - LCD chip select (CS)
// // pin 3 - LCD reset (RST)
// Adafruit_PCD8544 display = Adafruit_PCD8544(2, 3, 4, 5, 6);
// // Hardware SPI (faster, but must use certain hardware pins):
// // SCK is LCD serial clock (SCLK) - this is pin 13 on Arduino Uno
// // MOSI is LCD DIN - this is pin 11 on an Arduino Uno
// // pin 5 - Data/Command select (D/C)
// // pin 4 - LCD chip select (CS)
// // pin 3 - LCD reset (RST)
// // Adafruit_PCD8544 display = Adafruit_PCD8544(5, 4, 3);
// // Note with hardware SPI MISO and SS pins aren't used but will still be read
// // and written to during SPI transfer.  Be careful sharing these pins!
// #define NUMFLAKES 10
// #define XPOS 0
// #define YPOS 1
// #define DELTAY 2
// #define LOGO16_GLCD_HEIGHT 16
// #define LOGO16_GLCD_WIDTH 16
// static const unsigned char PROGMEM logo16_glcd_bmp[] =
//     {B00000000, B11000000,
//      B00000001, B11000000,
//      B00000001, B11000000,
//      B00000011, B11100000,
//      B11110011, B11100000,
//      B11111110, B11111000,
//      B01111110, B11111111,
//      B00110011, B10011111,
//      B00011111, B11111100,
//      B00001101, B01110000,
//      B00011011, B10100000,
//      B00111111, B11100000,
//      B00111111, B11110000,
//      B01111100, B11110000,
//      B01110000, B01110000,
//      B00000000, B00110000};
// void testdrawbitmap(const uint8_t *bitmap, uint8_t w, uint8_t h)
// {
//   uint8_t icons[NUMFLAKES][3];
//   randomSeed(666); // whatever seed
//   // initialize
//   for (uint8_t f = 0; f < NUMFLAKES; f++)
//   {
//     icons[f][XPOS] = random(display.width());
//     icons[f][YPOS] = 0;
//     icons[f][DELTAY] = random(5) + 1;
//     Serial.print("x: ");
//     Serial.print(icons[f][XPOS], DEC);
//     Serial.print(" y: ");
//     Serial.print(icons[f][YPOS], DEC);
//     Serial.print(" dy: ");
//     Serial.println(icons[f][DELTAY], DEC);
//   }
//   while (1)
//   {
//     // draw each icon
//     for (uint8_t f = 0; f < NUMFLAKES; f++)
//     {
//       display.drawBitmap(icons[f][XPOS], icons[f][YPOS], logo16_glcd_bmp, w, h, BLACK);
//     }
//     display.display();
//     delay(200);
//     while (Serial.available())
//     {
//       switch (Serial.read())
//       {
//       case 'w':
//         display.setContrast(display.getContrast() + 1);
//         break;
//       case 's':
//         if (display.getContrast())
//           display.setContrast(display.getContrast() - 1);
//         break;
//       case 'e':
//         display.setBias(display.getBias() + 1);
//         break;
//       case 'd':
//         if (display.getBias())
//           display.setBias(display.getBias() - 1);
//         break;
//       case 'R':
//         display.setReinitInterval(10);
//         break;
//       case 'r':
//         display.initDisplay();
//         display.setReinitInterval(0);
//         break;
//       }
//     }
//     Serial.print("contrast (w/s): 0x");
//     Serial.print(display.getContrast(), HEX);
//     Serial.print("   bias (e/d): 0x");
//     Serial.print(display.getBias(), HEX);
//     Serial.print("   reinitialize display (r/R): 0x");
//     Serial.print(display.getReinitInterval(), HEX);
//     Serial.print("   \r");
//     // then erase it + move it
//     for (uint8_t f = 0; f < NUMFLAKES; f++)
//     {
//       display.drawBitmap(icons[f][XPOS], icons[f][YPOS], logo16_glcd_bmp, w, h, WHITE);
//       // move it
//       icons[f][YPOS] += icons[f][DELTAY];
//       // if its gone, reinit
//       if (icons[f][YPOS] > display.height())
//       {
//         icons[f][XPOS] = random(display.width());
//         icons[f][YPOS] = 0;
//         icons[f][DELTAY] = random(5) + 1;
//       }
//     }
//   }
// }
// void testdrawchar(void)
// {
//   display.setTextSize(1);
//   display.setTextColor(BLACK);
//   display.setCursor(0, 0);
//   for (uint8_t i = 0; i < 168; i++)
//   {
//     if (i == '\n')
//       continue;
//     display.write(i);
//     //if ((i > 0) && (i % 14 == 0))
//     //display.println();
//   }
//   display.display();
// }
// void testdrawcircle(void)
// {
//   for (int16_t i = 0; i < display.height(); i += 2)
//   {
//     display.drawCircle(display.width() / 2, display.height() / 2, i, BLACK);
//     display.display();
//   }
// }
// void testfillrect(void)
// {
//   uint8_t color = 1;
//   for (int16_t i = 0; i < display.height() / 2; i += 3)
//   {
//     // alternate colors
//     display.fillRect(i, i, display.width() - i * 2, display.height() - i * 2, color % 2);
//     display.display();
//     color++;
//   }
// }
// void testdrawtriangle(void)
// {
//   for (int16_t i = 0; i < min(display.width(), display.height()) / 2; i += 5)
//   {
//     display.drawTriangle(display.width() / 2, display.height() / 2 - i,
//                          display.width() / 2 - i, display.height() / 2 + i,
//                          display.width() / 2 + i, display.height() / 2 + i, BLACK);
//     display.display();
//   }
// }
// void testfilltriangle(void)
// {
//   uint8_t color = BLACK;
//   for (int16_t i = min(display.width(), display.height()) / 2; i > 0; i -= 5)
//   {
//     display.fillTriangle(display.width() / 2, display.height() / 2 - i,
//                          display.width() / 2 - i, display.height() / 2 + i,
//                          display.width() / 2 + i, display.height() / 2 + i, color);
//     if (color == WHITE)
//       color = BLACK;
//     else
//       color = WHITE;
//     display.display();
//   }
// }
// void testdrawroundrect(void)
// {
//   for (int16_t i = 0; i < display.height() / 2 - 2; i += 2)
//   {
//     display.drawRoundRect(i, i, display.width() - 2 * i, display.height() - 2 * i, display.height() / 4, BLACK);
//     display.display();
//   }
// }
// void testfillroundrect(void)
// {
//   uint8_t color = BLACK;
//   for (int16_t i = 0; i < display.height() / 2 - 2; i += 2)
//   {
//     display.fillRoundRect(i, i, display.width() - 2 * i, display.height() - 2 * i, display.height() / 4, color);
//     if (color == WHITE)
//       color = BLACK;
//     else
//       color = WHITE;
//     display.display();
//   }
// }
// void testdrawrect(void)
// {
//   for (int16_t i = 0; i < display.height() / 2; i += 2)
//   {
//     display.drawRect(i, i, display.width() - 2 * i, display.height() - 2 * i, BLACK);
//     display.display();
//   }
// }
// void testdrawline()
// {
//   for (int16_t i = 0; i < display.width(); i += 4)
//   {
//     display.drawLine(0, 0, i, display.height() - 1, BLACK);
//     display.display();
//   }
//   for (int16_t i = 0; i < display.height(); i += 4)
//   {
//     display.drawLine(0, 0, display.width() - 1, i, BLACK);
//     display.display();
//   }
//   delay(250);
//   display.clearDisplay();
//   for (int16_t i = 0; i < display.width(); i += 4)
//   {
//     display.drawLine(0, display.height() - 1, i, 0, BLACK);
//     display.display();
//   }
//   for (int8_t i = display.height() - 1; i >= 0; i -= 4)
//   {
//     display.drawLine(0, display.height() - 1, display.width() - 1, i, BLACK);
//     display.display();
//   }
//   delay(250);
//   display.clearDisplay();
//   for (int16_t i = display.width() - 1; i >= 0; i -= 4)
//   {
//     display.drawLine(display.width() - 1, display.height() - 1, i, 0, BLACK);
//     display.display();
//   }
//   for (int16_t i = display.height() - 1; i >= 0; i -= 4)
//   {
//     display.drawLine(display.width() - 1, display.height() - 1, 0, i, BLACK);
//     display.display();
//   }
//   delay(250);
//   display.clearDisplay();
//   for (int16_t i = 0; i < display.height(); i += 4)
//   {
//     display.drawLine(display.width() - 1, 0, 0, i, BLACK);
//     display.display();
//   }
//   for (int16_t i = 0; i < display.width(); i += 4)
//   {
//     display.drawLine(display.width() - 1, 0, i, display.height() - 1, BLACK);
//     display.display();
//   }
//   delay(250);
// }
// void setup()
// {
//   Serial.begin(9600);
//   display.begin();
//   // init done
//   // you can change the contrast around to adapt the display
//   // for the best viewing!
//   display.setContrast(50);
//   display.display(); // show splashscreen
//   delay(2000);
//   display.clearDisplay(); // clears the screen and buffer
//   // draw a single pixel
//   display.drawPixel(10, 10, BLACK);
//   display.display();
//   delay(2000);
//   display.clearDisplay();
//   // draw many lines
//   testdrawline();
//   display.display();
//   delay(2000);
//   display.clearDisplay();
//   // draw rectangles
//   testdrawrect();
//   display.display();
//   delay(2000);
//   display.clearDisplay();
//   // draw multiple rectangles
//   testfillrect();
//   display.display();
//   delay(2000);
//   display.clearDisplay();
//   // draw mulitple circles
//   testdrawcircle();
//   display.display();
//   delay(2000);
//   display.clearDisplay();
//   // draw a circle, 10 pixel radius
//   display.fillCircle(display.width() / 2, display.height() / 2, 10, BLACK);
//   display.display();
//   delay(2000);
//   display.clearDisplay();
//   testdrawroundrect();
//   delay(2000);
//   display.clearDisplay();
//   testfillroundrect();
//   delay(2000);
//   display.clearDisplay();
//   testdrawtriangle();
//   delay(2000);
//   display.clearDisplay();
//   testfilltriangle();
//   delay(2000);
//   display.clearDisplay();
//   // draw the first ~12 characters in the font
//   testdrawchar();
//   display.display();
//   delay(2000);
//   display.clearDisplay();
//   // text display tests
//   display.setTextSize(1);
//   display.setTextColor(BLACK);
//   display.setCursor(0, 0);
//   display.println("Hello, world!");
//   display.setTextColor(WHITE, BLACK); // 'inverted' text
//   display.println(3.141592);
//   display.setTextSize(2);
//   display.setTextColor(BLACK);
//   display.print("0x");
//   display.println(0xDEADBEEF, HEX);
//   display.display();
//   delay(2000);
//   // rotation example
//   display.clearDisplay();
//   display.setRotation(1); // rotate 90 degrees counter clockwise, can also use values of 2 and 3 to go further.
//   display.setTextSize(1);
//   display.setTextColor(BLACK);
//   display.setCursor(0, 0);
//   display.println("Rotation");
//   display.setTextSize(2);
//   display.println("Example!");
//   display.display();
//   delay(2000);
//   // revert back to no rotation
//   display.setRotation(0);
//   // miniature bitmap display
//   display.clearDisplay();
//   display.drawBitmap(30, 16, logo16_glcd_bmp, 16, 16, 1);
//   display.display();
//   // invert the display
//   display.invertDisplay(true);
//   delay(1000);
//   display.invertDisplay(false);
//   delay(1000);
//   // draw a bitmap icon and 'animate' movement
//   testdrawbitmap(logo16_glcd_bmp, LOGO16_GLCD_WIDTH, LOGO16_GLCD_HEIGHT);
// }
// void loop()
// {
// }

// Backlight dimming test
// Not quite sure about this.. I heard a 39ohm resistor to gpio could control it. dimming on would be ace
// but - don't stress too much, if it's just on all the tiem that'd be okay too
// https://www.algissalys.com/electronics/nokia-5110-lcd-backlight-to-ground-using-gpio
void setup()
{
  pinMode(22, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(A7, OUTPUT);
}
void loop()
{
  digitalWrite(22, 0);
  delay(200);
  digitalWrite(26, 0);
  delay(200);
  digitalWrite(A7, 0);
  delay(200);
  digitalWrite(26, 0);
  delay(200);
  digitalWrite(26, 0);
  delay(200);
}