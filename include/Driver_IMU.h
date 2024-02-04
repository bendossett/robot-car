#ifndef DRIVER_IMU_H
#define DRIVER_IMU_H

#include <Arduino.h>
#include <Adafruit_MPU6050.h>

// https://registry.platformio.org/libraries/adafruit/Adafruit%20MPU6050/examples/basic_readings/basic_readings.ino

class Driver_IMU
{
private:
    Adafruit_MPU6050 mpu;
    
public:
    Driver_IMU();
    ~Driver_IMU();

    void init();
    void read(sensors_event_t* accel, sensors_event_t* gyro, sensors_event_t* temp);
};


#endif