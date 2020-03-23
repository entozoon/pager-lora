#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

U8G2_ST7920_128X64_1_SW_SPI u8g2(
    U8G2_R0, // rotation
    PA1,     // Clock "E" enable?
    PA2,     // Data "R/W" might have this and next wrong way.. but meh
    PA3,     // CS "RS"
    PA4      // Reset "RST"
);
// Also connect +5v to VCC, BLA
// and - to GND, PSB, BLK

char alphabet[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

void setup(void)
{
  u8g2.begin();
}

void loop(void)
{
  u8g2.firstPage();
  do
  {
    // https://github.com/olikraus/u8g2/wiki/u8g2reference
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(0, 24, "Hello World!");

    // Can't bleeding get it to output a random string
    // char char_array[] = {""};
    // char_array[0] = char(random(0, 9));
    // // strcpy(char_array, alphabet[random(0, 25)].c_str());

    u8g2.drawStr(40, 50, char_array);

    u8g2.drawBox(random(0, 100), random(30, 50), 8, 8);

    // Not amazing, then again I've no idea what the page system is so..

  } while (u8g2.nextPage());
}