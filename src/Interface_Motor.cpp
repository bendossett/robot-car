#include "Interface_Motor.h"

Interface_Motor::Interface_Motor()
{
    motor_driver.init();
}

Interface_Motor::~Interface_Motor()
{
}

void Interface_Motor::control(Direction direction, uint8_t speed)
{
    switch (direction)
    {
    case Forward:
        motor_driver.control(Direction::Forward, speed, Direction::Forward, speed);
        break;
    case Backward:
        motor_driver.control(Direction::Backward, speed, Direction::Backward, speed);
        break;
    case Left:
        motor_driver.control(Direction::Forward, speed, Direction::Backward, speed);
        break;
    case Right:
        motor_driver.control(Direction::Backward, speed, Direction::Forward, speed);
        break;
    case LeftForward:
        motor_driver.control(Direction::Forward, speed, Direction::Forward, speed / 2);
        break;
    case LeftBackward:
        motor_driver.control(Direction::Backward, speed, Direction::Backward, speed / 2);
        break;
    case RightForward:
        motor_driver.control(Direction::Forward, speed / 2, Direction::Forward, speed);
        break;
    case RightBackward:
        motor_driver.control(Direction::Backward, speed / 2, Direction::Backward, speed);
        break;
    case Stop:
        motor_driver.control(Direction::Stop, 0, Direction::Stop, 0);
        break;
    default:
        break;
    }
}