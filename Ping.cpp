#include <Ping.h>

// Ping constructor sets the given pin as output.
Ping::Ping(uint8_t pin)
{
  this->pin = pin;
  pinMode(this->pin, OUTPUT);
  digitalWrite(this->pin, LOW);
}

// Duration returns the number of milliseconds that takes an emitted pulse to
// bounce back to the PING))) sensor. This number is directly proportional to
// the travelled distance and can be converted to centimeters or inches by
// wrapping this function inside PING_DISTANCE_CM or PING_DISTANCE_IN.
//
// Example:
//
// ping->Duration() * PING_DISTANCE_CM
//
// or
//
// ping->Duration() * PING_DISTANCE_IN
//
// Duration will return PING_MAX_DISTANCE in case the distance could not be
// measured.
long Ping::Duration()
{
  long d;

  // Emiting a pulse.
  pinMode(this->pin, OUTPUT);
  digitalWrite(this->pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(this->pin, LOW);

  pinMode(this->pin, INPUT);

  // pulseIn measures the total duration, we just need the half since that was
  // what the pulse needed to bounce back to the sendor.
  d = pulseIn(this->pin, HIGH) / 2;

  if (d > PING_MAX_DISTANCE) {
    return PING_UNKNOWN_DISTANCE;
  }

  return d;
}
