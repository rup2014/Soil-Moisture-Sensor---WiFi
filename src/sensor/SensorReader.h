#ifndef SENSOR_READER_H
#define SENSOR_READER_H

class SensorReader{
    public:
        SensorReader();
        void initSensorReader();
        int readSensor();
};

#endif