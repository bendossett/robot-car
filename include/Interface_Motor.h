#ifndef INTERFACE_MOTOR_H
#define INTERFACE_MOTOR_H

#include <Arduino.h>
#include "Driver_Motor.h"

class Interface_Motor
{
private:
    Driver_Motor motor_driver;
public:
    Interface_Motor(/* args */);
    ~Interface_Motor();

    void control(Direction direction, uint8_t speed);
};

#endif