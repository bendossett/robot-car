#include "Driver_Servo.h"

Driver_Servo::Driver_Servo() {}

Driver_Servo::~Driver_Servo() {}

void Driver_Servo::init(unsigned int position_angle)
{
    servo.attach(PIN_SERVO_Z, 500, 2400);
    servo.write(position_angle);
    delay(500);    // delay(10);

}

void Driver_Servo::control(unsigned int position_angle, unsigned int delay_ms)
{
    servo.write(position_angle);
    delay(delay_ms);
}