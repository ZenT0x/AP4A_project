#include <iostream>
#include "Server.hpp"
#include "Sensor.hpp"

int main()
{   
    Server<std::string> stringServer;
    Server<int> intServer;
    Server<float> floatServer;

    Sensor<std::string> stringSensor("stringSensor", "Hello World!");
    Sensor<int> Temperature("Temperature", 25);
    Sensor<float> Pressure("Pressure", 1.2);
    Sensor<float> Humidity("Humidity", 0.5);

    stringServer << stringSensor;
    intServer << Temperature;
    floatServer << Pressure;
    floatServer << Humidity;

    return 0;
}


