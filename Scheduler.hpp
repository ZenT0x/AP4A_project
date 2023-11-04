/**
 * @file Scheduler.hpp
 * @brief Scheduler class definition.
 *
 * This file contains the definition of the Scheduler class, which is responsible for
 * creating and managing sensors and servers, and receiving data from them.
 */

#pragma once

#include "Server.hpp"
#include "Sensor.hpp"
#include <thread>
#include <chrono>

using namespace std;

/**
 * @class Scheduler
 * @brief Scheduler class.
 *
 * This class is responsible for creating and managing sensors and servers, and receiving data from them.
 */
class Scheduler
{   
    private:
        bool sensorLog; ///< Flag indicating whether to log sensor messages.
        bool serverLog; ///< Flag indicating whether to log server messages.

    public:
        /**
         * @brief Scheduler constructor
         *
         * This constructor creates a Scheduler object.
         *
         * @param mainLog Flag indicating whether to log main messages.
         * @param serverLog Flag indicating whether to log server messages.
         * @param sensorLog Flag indicating whether to log sensor messages.
         */
        Scheduler(bool mainLog, bool serverLog, bool sensorLog);
        
        /**
         * @brief Function to receive data from a sensor and send it to a server.
         *
         * This function receives data from a sensor and sends it to a server. It runs in a separate thread
         * and updates the data every `updateTime` milliseconds.
         *
         * @param server The server to send the data to.
         * @param sensor The sensor to receive the data from.
         * @param updateTime The time in milliseconds between updates.
         */
        template <typename SensorTemplate>
        void receiveData(Server& server, SensorTemplate& sensor, int updateTime);
};

template <typename SensorTemplate>
void Scheduler::receiveData(Server& server, SensorTemplate& sensor, int updateTime)
{   
    // With thread, server will get the value of sensor every 5 seconds
    thread([this, &server, &sensor, updateTime]() {
        while (true)
        {   
            sensor.aleaGenVal();
            server << sensor;
            this_thread::sleep_for(std::chrono::milliseconds(updateTime));
        }
    }).detach();
}