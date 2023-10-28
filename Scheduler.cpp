#include "Scheduler.hpp"
#include "Server.hpp"
#include "Sensor.hpp"
#include <iostream>

using namespace std;

Scheduler::Scheduler(bool mainLog, bool serverLog, bool sensorLog)
{
    if (mainLog)
    {
        cout << endl;
        cout << "Program started" << endl;
        cout << endl;
        cout << "[Scheduler] Scheduler created" << endl;
    }

    SensorInt Temperature("Temperature", 0, sensorLog);
    SensorInt Humidity("Humidity", 0, serverLog);
    SensorFloat Sound("Sound", 0, serverLog);
    SensorDouble Light("Light", 0, serverLog);
    
}
