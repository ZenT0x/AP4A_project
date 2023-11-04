#include "Scheduler.hpp"
#include "Server.hpp"
#include "Sensor.hpp"
#include <iostream>
#include <conio.h>

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

    Server server1(serverLog);

    receiveData(server1, Temperature);

    while (true) {
        // Code to execute at each iteration of the loop
        // Display a message to the console
        std::cout << "Appuie sur Entree pour sortir..." << std::endl;
        
        // Check if the user has pressed Enter
        if (std::cin.get() == 'q') {
            break;  // Quit the loop if Enter is pressed
        }
    }

}

void Scheduler::run()
{   
    
}

    