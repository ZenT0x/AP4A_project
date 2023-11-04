#pragma once

#include "Server.hpp"
#include "Sensor.hpp"
#include <thread>
#include <chrono>

using namespace std;

class Scheduler
{   
    private:
        bool sensorLog;
        bool serverLog;

    public:
        Scheduler(bool mainLog, bool serverLog, bool sensorLog);
        
        template <typename SensorTemplate>
        void receiveData(Server& server, SensorTemplate& sensor);
        void run();
};

template <typename SensorTemplate>
void Scheduler::receiveData(Server& server, SensorTemplate& sensor)
{   
    cout << "[Scheduler] Sending data to server" << endl;
    // With thread, server will get the value of sensor every 5 seconds
    thread([this, &server, &sensor]() {
        cout << "[Scheduler] Before while" << endl;
        while (true)
        {   
            cout << "[Scheduler] Thread" << endl;
            server << sensor;
            this_thread::sleep_for(std::chrono::seconds(1));
        }
    }).detach();
}




