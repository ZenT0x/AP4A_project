#include "Scheduler.hpp"
#include "Server.hpp"
#include "Sensor.hpp"
#include <iostream>


Scheduler::Scheduler()
{
    std::cout << "[Scheduler] Scheduler created" << std::endl;
    Server<std::string> stringServer;
    Server<int> intServer;
    Server<float> floatServer(true,true);

    Server<int> testServer(true,true);

    std::cout << std::endl;

    Sensor<std::string> stringSensor("stringSensor", "Hello World!");
    Sensor<int> Temperature("Temperature", 25);
    Sensor<float> Pressure("Pressure", 1.2);
    Sensor<float> Humidity("Humidity", 0.5);

    std::cout << std::endl;

    stringServer << stringSensor;
    intServer << Temperature;
    floatServer << Pressure;
    floatServer << Humidity;

    std::cout << std::endl;
}

