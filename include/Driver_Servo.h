#ifndef DRIVER_SERVO_H
#define DRIVER_SERVO_H

#include <Arduino.h>
#include <Servo.h>

class Driver_Servo
{
public:
    Driver_Servo();
    ~Driver_Servo();

    void init(unsigned int position_angle);
    void control(unsigned int position_angle, unsigned int delay_ms);

private:
    #define PIN_SERVO_Z 10

    Servo servo;
};

#endif