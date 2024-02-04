#include "Driver_Motor.h"

/*Motor control*/
void Driver_Motor::init(void)
{
  pinMode(PIN_Motor_PWMA, OUTPUT);
  pinMode(PIN_Motor_PWMB, OUTPUT);
  pinMode(PIN_Motor_AIN_1, OUTPUT);
  pinMode(PIN_Motor_BIN_1, OUTPUT);
  pinMode(PIN_Motor_STBY, OUTPUT);
}

void Driver_Motor::control(uint8_t direction_A, uint8_t speed_A, uint8_t direction_B, uint8_t speed_B)
{
  digitalWrite(PIN_Motor_STBY, HIGH);
  { // A...Right

    switch (direction_A) // 方向控制
    {
    case Direction::Forward:
      digitalWrite(PIN_Motor_AIN_1, HIGH);
      analogWrite(PIN_Motor_PWMA, speed_A);
      break;
    case Direction::Backward:

      digitalWrite(PIN_Motor_AIN_1, LOW);
      analogWrite(PIN_Motor_PWMA, speed_A);
      break;
    case Direction::Stop:
      analogWrite(PIN_Motor_PWMA, 0);
      digitalWrite(PIN_Motor_STBY, LOW);
      break;
    default:
      analogWrite(PIN_Motor_PWMA, 0);
      digitalWrite(PIN_Motor_STBY, LOW);
      break;
    }
  }

  { // B...Left
    switch (direction_B)
    {
    case Direction::Forward:
      digitalWrite(PIN_Motor_BIN_1, HIGH);

      analogWrite(PIN_Motor_PWMB, speed_B);
      break;
    case Direction::Backward:
      digitalWrite(PIN_Motor_BIN_1, LOW);
      analogWrite(PIN_Motor_PWMB, speed_B);
      break;
    case Direction::Stop:
      analogWrite(PIN_Motor_PWMB, 0);
      digitalWrite(PIN_Motor_STBY, LOW);
      break;
    default:
      analogWrite(PIN_Motor_PWMB, 0);
      digitalWrite(PIN_Motor_STBY, LOW);
      break;
    }
  }
}
