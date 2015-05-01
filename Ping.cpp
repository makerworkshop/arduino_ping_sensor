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
// the travelled distance and can be converted into millimeters, centimeters or
// inches by wrapping this function inside PING_DISTANCE_MM, PING_DISTANCE_CM
// or PING_DISTANCE_IN.
//
// Example:
//
// PING_DISTANCE_CM(ping->Duration())
//
// or
//
// PING_DISTANCE_IN(ping->Duration())
//
// Duration will return PING_UNKNOWN_DISTANCE in case the distance could not be
// measured (either too far or too close to an obstacle).
long Ping::Duration()
{
  long d;

  // Emiting a pulse.
  pinMode(this->pin, OUTPUT);
  digitalWrite(this->pin, LOW);
  delayMicroseconds(2);

  digitalWrite(this->pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(this->pin, LOW);

  pinMode(this->pin, INPUT);

  // pulseIn measures the total duration, we just need the half since that was
  // what the pulse needed to bounce back to the sendor.
  d = pulseIn(this->pin, HIGH) / 2;

  if (d > PING_MAX_DISTANCE) {
    return PING_MAX_DISTANCE;
  }

  return d;
}
