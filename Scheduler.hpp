#pragma once

#include "Server.hpp"
#include "Sensor.hpp"

class Scheduler
{   
    private:
        bool sensorLog;
        bool serverLog;
        SensorInt Temperature;
        SensorInt Humidity;
        SensorFloat Sound;
        SensorDouble Light;

    public:
        Scheduler(bool mainLog, bool serverLog, bool sensorLog);
        
        template <typename SensorTemplate>
        void receiveData(SensorTemplate& server, SensorTemplate& sensor);
        void run();
};   
