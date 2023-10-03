#include <iostream>
#include "Server.hpp"
#include "Sensor.hpp"

int main()
{
    Server server;
    Sensor sensor1("Temperature", "25");
    Sensor sensor2("Temperature", "26");

    server << sensor1 << sensor2;
    return 0;
}

