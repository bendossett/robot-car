#include "Driver_IMU.h"

Driver_IMU::Driver_IMU() {}

Driver_IMU::~Driver_IMU() {}

void Driver_IMU::init()
{
    mpu.begin();
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
    delay(100);
}

void Driver_IMU::read(sensors_event_t* accel, sensors_event_t* gyro, sensors_event_t* temp)
{
    mpu.getEvent(accel, gyro, temp);
}