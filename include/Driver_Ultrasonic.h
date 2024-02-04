#ifndef DRIVER_ULTRASONIC_H
#define DRIVER_ULTRASONIC_H

#include <Arduino.h>

class Driver_Ultrasonic
{
public:
    Driver_Ultrasonic();
    ~Driver_Ultrasonic();

    void init();
    unsigned int read();

private:
#define TRIG_PIN 13      // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN 12      // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200
};

#endif