#pragma once

class Scheduler
{   
    private:
        bool sensorLog;
        bool serverLog;
    public:
        Scheduler(bool mainLog, bool serverLog, bool sensorLog);
};   
