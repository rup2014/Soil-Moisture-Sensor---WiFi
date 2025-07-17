#include "SensorReader.h"
#include "driver/touch_sensor.h"
#include "Arduino.h"

SensorReader::SensorReader(){};

void SensorReader::initSensorReader(){
    touch_pad_init();
    touch_pad_set_voltage(TOUCH_HVOLT_2V4, TOUCH_LVOLT_0V5, TOUCH_HVOLT_ATTEN_1V);
    touch_pad_config(TOUCH_PAD_NUM2, 0);
}

int SensorReader::readSensor(){
    return touchRead(TOUCH_PAD_NUM2);
}