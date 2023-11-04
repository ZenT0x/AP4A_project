/**
 * @file Scheduler.cpp
 * @brief Scheduler class implementation.
 *
 * This file contains the implementation of the Scheduler class, which is responsible for
 * creating and managing sensors and servers, and receiving data from them.
 */

#include "Scheduler.hpp"
#include "Server.hpp"
#include "Sensor.hpp"
#include <iostream>
#include <chrono>

#define TEMPERATURE_UPDATE_TIME 3000
#define HUMIDITY_UPDATE_TIME 5000
#define LIGHT_UPDATE_TIME 2000
#define SOUND_UPDATE_TIME 1000

using namespace std;

/**
 * @brief Scheduler constructor
 *
 * This constructor creates a Scheduler object, creates sensors and servers, and starts
 * receiving data from them. It also logs messages if the corresponding log flags are set.
 * The program can be exited by pressing Enter.
 *
 * @param mainLog Flag indicating whether to log main messages.
 * @param serverLog Flag indicating whether to log server messages.
 * @param sensorLog Flag indicating whether to log sensor messages.
 */
Scheduler::Scheduler(bool mainLog, bool serverLog, bool sensorLog)
{   
    cout << "Press Enter to exit program" << endl;
    // Wait 2 second before starting program
    this_thread::sleep_for(std::chrono::seconds(2));


    if (mainLog)
    {
        cout << endl;
        cout << "Program started" << endl;
        cout << endl;
        cout << "[Scheduler] Scheduler created" << endl;
        cout << endl;
        cout << "[Scheduler] Creating sensors" << endl;
    }

    SensorFloat Temperature("Temperature", 0, sensorLog);
    SensorFloat Humidity("Humidity", 0, sensorLog);
    SensorBool Light("Light", false, sensorLog);
    SensorInt Sound("Sound", 0, sensorLog);

    if (mainLog)
    {
        cout << endl;
        cout << "[Scheduler] Creating servers" << endl;
    }

    Server server(serverLog);

    receiveData(server, Temperature, TEMPERATURE_UPDATE_TIME);
    receiveData(server, Humidity, HUMIDITY_UPDATE_TIME);
    receiveData(server, Light, LIGHT_UPDATE_TIME);
    receiveData(server, Sound, SOUND_UPDATE_TIME);

    while (true) {
        // Exit program if user press Enter
        if (cin.get() == '\n') {
            break;  
        }
    }
}