#include "Scheduler.hpp"
#include "Server.hpp"
#include "Sensor.hpp"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

Scheduler::Scheduler(bool mainLog, bool serverLog, bool sensorLog)
{
    if (mainLog)
    {
        cout << endl;
        cout << "Program started" << endl;
        cout << endl;
        cout << "[Scheduler] Scheduler created" << endl;
        cout << endl;
        cout << "[Scheduler] Creating sensors" << endl;
    }

    SensorInt Temperature("Temperature", 0, sensorLog);
    SensorInt Humidity("Humidity", 0, serverLog);
    SensorFloat Sound("Sound", 0, serverLog);
    SensorDouble Light("Light", 0, serverLog);

    if (mainLog)
    {
        cout << endl;
        cout << "[Scheduler] Creating servers" << endl;
    }

    ServerInt serverInt(serverLog);
    ServerFloat serverFloat(serverLog);
    ServerDouble serverDouble(serverLog);
    
    
}

template <typename SensorTemplate>
void Scheduler::receiveData(SensorTemplate& server, SensorTemplate& sensor)
{
    // With thread, server will get the value of sensor every 5 seconds
    thread([this, &server, &sensor]() {
        while (true)
        {
            server << sensor;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }).detach();
}

void Scheduler::run()
{   
    SensorInt Temperature("Temperature", 0, sensorLog);
    SensorInt Humidity("Humidity", 0, serverLog);
    SensorFloat Sound("Sound", 0, serverLog);
    SensorDouble Light("Light", 0, serverLog);

    ServerInt serverInt(serverLog);
    ServerFloat serverFloat(serverLog);
    ServerDouble serverDouble(serverLog);

    receiveData(serverInt, Temperature);
}

    