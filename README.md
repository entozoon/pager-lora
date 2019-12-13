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
    240mAh / 32mA = 7.5 hours

Woah. I mean, these are conservative numbers too. Not three bad.
So yeah, sleep both chips if possible when closed and poss use an Arduino (5mA).

### C rating?

Literally anything is fine.
Peak current, with lit screen and full transmit is like 220mA, so 0.5C @ 500mA is enough. (18650 are 1C)

### Sleep LoRa chip

Just a reminder to sleep this along with the microcontroller.

## Battery

5V step ups bitch out under .5v, which won't matter much, but the efficiency varies with input voltage (and current): http://www.hobbytronics.co.uk/u1v10f5-5v-regulator

| Battery      |    V |  mAh | Effic | ->~mAh | Life(h) mAh/32mA | Notes                      |
| ------------ | ---: | ---: | ----: | -----: | ---------------: | -------------------------- |
| AAA (r/c)    | 1.5v | 1000 |  @70% |    700 |               22 |                            |
| AAA (r/c) x2 | 1.5v | 2000 |  @70% |   1400 |               44 |                            |
| AA (r/c)     | 1.5v | 2400 |  @70% |   1680 |               53 |                            |
| Lipo 50x30mm | 3.7v | 2000 |  @90% |   1800 |               56 | Better form factor than AA |
| 18650        | 3.7v | 2400 |  @90% |   2160 |               66 | All lipos easy to charge   |
| Lipo 90x60mm | 3.7v | 4000 |  @90% |   3600 |              113 | Phone bat size, affordable |

Lipo batteries supposedly self-disarge at only 5%/month (despite my experience), not far off alkaline.
So any lipo really, high mAh as possible for the best form factor.
But deeefinitely invest in a voltmeter setup (see below). Perhaps flash the screen hard and/or chirp for a turn off.

## Battery monitoring

Feed battery into analogue input, with a voltage divider to reduce it.

Wemos A0 has a voltage divider built in. 220k / 100k (2/3rdsness).
People say it has a range of 3.3V, but I should test that.

    +++++++++
        |
      [10k]
        |
        |----(100pF -> 1nF)---> analogue input
        |    reduce wobble
        |
      [10k]
        |
    ---------

    V divideness = (R1 / R1 + R2)
                 = 1 / 2

So if my lipo spits out a mad 4.6V, A0 would receive 2.3V.

| Lipo V | Desc   | Dividered | A0 (theory) | Human  |
| ------ | ------ | --------: | ----------: | ------ |
| 4.6    | Pumped |       2.3 |         713 | 100%   |
| 4.2    | Full   |       2.1 |         652 | 100%   |
| 4      | Good   |         2 |         621 | 75%    |
| 3.86   | Mid    |      1.93 |         599 | 50%    |
| 3.75   | Low    |     1.875 |         582 | 20% !  |
| 3.7    | Low    |      1.85 |         574 | 10% !  |
| 3.5    | Dead   |      1.75 |         543 | 0% off |

    A0 (theory) = Dividered V / 3.3 * 1024
