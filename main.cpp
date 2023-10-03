#include <iostream>
#include "Server.hpp"
#include "Sensor.hpp"

int main()
{
    Server<int> serverInt;
    Server<double> serverDouble;
    Server<std::string> serverString;
    Server<bool> serverBool;


    Sensor<int> sensorInt("Temperature", 25);
    Sensor<double> sensorDouble("Humidity", 0.5);
    Sensor<std::string> sensorString("Pressure", "Normal");
    Sensor<bool> sensorBool("Motion", true);

    serverInt << sensorInt;
    serverDouble << sensorDouble;
    serverString << sensorString;
    serverBool << sensorBool;
    

    return 0;
}


