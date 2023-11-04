#pragma once

#include "Server.hpp"
#include "Sensor.hpp"

class Scheduler
{   
    private:
        bool sensorLog;
        bool serverLog;

    public:
        Scheduler(bool mainLog, bool serverLog, bool sensorLog);
        
        template <typename SensorTemplate>
        void receiveData(SensorTemplate& server, SensorTemplate& sensor);
        void run();
};   
