/*
 * Copyright (c) 2014-2015 José Carlos Nieto, https://menteslibres.net/xiam
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * */

// Based on http://arduino.cc/en/Tutorial/ping and
// http://www.parallax.com/downloads/ping-ultrasonic-distance-sensor-bs2-example-code
//
// Thanks:
// - David A. Mellis
// - Tom Igoe/
// - Jon Williams -- Parallax, Inc.
//

#ifndef MAKERWORKSHOP_PING
#define MAKERWORKSHOP_PING

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define PING_MAX_DISTANCE       11800
#define PING_UNKNOWN_DISTANCE   -1

// PING_SPEED_OF_SOUND constant defines how many millimeters does the sound
// travel in one second.
#define PING_SPEED_OF_SOUND 340290

// PING_DISTANCE_MM(x) macro transforms x (duration of a pulse bounce) into
// millimeters.
#define PING_DISTANCE_MM(x) (x != PING_UNKNOWN_DISTANCE ? x/2.939 : PING_UNKNOWN_DISTANCE) // x/(1e6/PING_SPEED_OF_SOUND)

// PING_DISTANCE_CM(x) macro transforms x (duration of a pulse bounce) into
// centimeters.
#define PING_DISTANCE_CM(x) (x != PING_UNKNOWN_DISTANCE ? x/29.39 : PING_UNKNOWN_DISTANCE) // x/(1e6/(PING_SPEED_OF_SOUND/10))

// PING_DISTANCE_IN(x) macro transforms x (duration of a pulse bounce in
// microseconds) into inches.
#define PING_DISTANCE_IN(x) (x != PING_UNKNOWN_DISTANCE ? x/74.64 : PING_UNKNOWN_DISTANCE) // x/(1e6/(PING_SPEED_OF_SOUND/25.4))

class Ping {
  private:
    uint8_t pin;
  public:
    Ping(uint8_t pin);
    long Duration();
};

#endif
