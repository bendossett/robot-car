#include <Arduino.h>
#include "Interface_Ranging.h"
#include "Driver_IMU.h"

Interface_Ranging ranging;
RangingResult ranging_result;

Driver_IMU imu_driver;

const uint8_t SERIAL_BUFF_LEN = 256;
byte serial_buff[SERIAL_BUFF_LEN];

void setup()
{
    Serial.begin(115200);

    ranging.init(10);

    imu_driver.init();
}

void loop()
{
    if (Serial.available() > 0)
    {
        Serial.readBytesUntil('\n', serial_buff, SERIAL_BUFF_LEN);
        // Handle motor control
    }
    ranging.step(&ranging_result);
    

    // Serial.print(latest_angle);
    // Serial.print(" ");

    // Serial.println(latest_range);
}
