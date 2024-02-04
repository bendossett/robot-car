#ifndef INTERFACE_RANGING_H
#define INTERFACE_RANGING_H

#include "Driver_Servo.h"
#include "Driver_Ultrasonic.h"

typedef struct ranging_result
{
    const byte msg_type = 1;
    unsigned int angle;
    unsigned int range;
} RangingResult;

class Interface_Ranging
{
private:
    uint8_t angle = 90;
    uint8_t step_size;
    int8_t step_direction = 1;

    Driver_Servo servo_driver;
    Driver_Ultrasonic ultrasonic_driver;

public:
    Interface_Ranging();
    ~Interface_Ranging();

    void init(uint8_t step_size);
    void step(RangingResult* result);
};

#endif