#include "Driver_Ultrasonic.h"

Driver_Ultrasonic::Driver_Ultrasonic() {}

Driver_Ultrasonic::~Driver_Ultrasonic() {}

void Driver_Ultrasonic::init()
{
    pinMode(ECHO_PIN, INPUT);
    pinMode(TRIG_PIN, OUTPUT);
}

unsigned int Driver_Ultrasonic::read()
{
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    return ((unsigned int)pulseIn(ECHO_PIN, HIGH) / 58);
}