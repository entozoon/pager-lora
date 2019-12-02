# Pager Lora

## Ingredients

- Arduino / ESP8266 ?
  Arduino is more conservative but doesn't seem to be the popular choice. I mean, speed might be an issue with transmission so bang it out on a Wemos with WIFI disabled.

## Goals

- Clamshell
- Nokia 5110 screen / e-ink
- Buzz tune on receipt
- Opening wakes up device screen
- Small as poss, but poss 18520 batteries, so..
- Lora communication over 300m

## Input

Mobile keypad text is a fun way to go. Revive that old skill.

### Drawing?

Would be nice, but bandwidth is limited, as well as rendering capabilities so.. it'd be a whole thing. Couldn't be real-time.. but still an option if I make a larger device.

## Comms

| Send Device      |       Listen Device        |        User |
| ---------------- | :------------------------: | ----------: |
| Listening always |      Listening always      |             |
|                  |                            |             |
| Emit (n?)        |                            |        Send |
|                  |          Receive           |        Buzz |
|                  |      Store to EEPROM       |             |
|                  | Emit message received? meh |             |
| Stop emitting    |                            |             |
|                  | Screen on, display message | Open device |
|                  |                            |             |

## Power

The power concerns are real. So let's make sure to do all dis:

### Disable WIFI on microcontroller

`WiFi.mode(WIFI_OFF);`

### Sleep

If possible, I mean perhaps it could sleep half the time? Let's have a shufty at some power requirements. Complete conjecture, but anyways:

- Microcontroller
  General: 20mA ESP w/out WIFI or 5mA for pro mini
  Sleep: Negligible

- LoRa (3.3v)
  Receiver: ≦ 10mA (LnaBoost off, band 1)
  Transmit: ≦ 120mA (+ 20dBm)
  Sleep: Negligible
  Total, if listening always and transmitting like 1% of the time: 11mA

- Screen
  Unlit: 1mA
  Backlit: <= 80mA, so maybe don't bother!

- 18650 2400mah 3.7v
  5v converters are supposedly 90% efficient so 2160mAh

So, assuming they're always listening and transmit at glorious 28.8kbps modem style speed now and then:

    Battery capacity (mA/h) / Current draw (mA) = hours of battery life  .. right?

    2160mAh / 32mA = 67 hours
    900mAh / 32mA = 28 hours

Woah. I mean, these are conservative numbers too. Not three bad.
So yeah, sleep both chips if possible when closed and poss use an Arduino (5mA).

### Sleep LoRa chip

Just a reminder to sleep this along with the microcontroller.
