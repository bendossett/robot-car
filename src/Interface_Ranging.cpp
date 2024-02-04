#include "Interface_Ranging.h"

Interface_Ranging::Interface_Ranging()
{
}

Interface_Ranging::~Interface_Ranging() {}

void Interface_Ranging::init(uint8_t step_size)
{
    this->step_size = step_size;
    servo_driver.init(angle);
    ultrasonic_driver.init();
}

void Interface_Ranging::step(RangingResult* result)
{
    angle += step_direction * step_size;

    if (angle >= 180)
    {
        angle = 180;
        step_direction *= -1;
    }
    else if (angle <= 0)
    {
        angle = 0;
        step_direction *= -1;
    }

    servo_driver.control(angle, 70);
    result->angle = angle;
    result->range = ultrasonic_driver.read();
}