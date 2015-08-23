#include <Ping.h>

#define PING_SENSOR_PIN   4

#define SERIAL_BAUD_RATE  115200

Ping *ping;

void setup()
{
  Serial.begin(SERIAL_BAUD_RATE);
  ping = new Ping(PING_SENSOR_PIN);
}

void loop()
{
  long distance = ping->Duration();

  if (distance != PING_UNKNOWN_DISTANCE) {
    Serial.print("Pulse duration: ");
    Serial.print(distance);
    Serial.println("us");

    Serial.print("Pulse distance (millimeters): ");
    Serial.print(PING_DISTANCE_MM(distance));
    Serial.println("mm");

    Serial.print("Pulse distance (centimeters): ");
    Serial.print(PING_DISTANCE_CM(distance));
    Serial.println("cm");

    Serial.print("Pulse distance (inches): ");
    Serial.print(PING_DISTANCE_IN(distance));
    Serial.println("in");
  } else {
    Serial.println("Could not measure distance!");
  }

  delay(500);
}
