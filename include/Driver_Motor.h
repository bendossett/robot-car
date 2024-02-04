#ifndef DRIVER_MOTOR_H
#define DRIVER_MOTOR_H

#include <Arduino.h>

enum Direction
{
    Forward,
    Backward,
    Left,
    Right,
    LeftForward,
    LeftBackward,
    RightForward,
    RightBackward,
    Stop
};

/*Motor*/
class Driver_Motor
{
public:
  void init(void);
#if _Test_DRIVER
  void Test(void);
#endif
  void control(uint8_t direction_A, uint8_t speed_A, uint8_t direction_B, uint8_t speed_B);

private:
#define PIN_Motor_PWMA 5
#define PIN_Motor_PWMB 6
#define PIN_Motor_BIN_1 8
#define PIN_Motor_AIN_1 7
#define PIN_Motor_STBY 3
};

#endif
