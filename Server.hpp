#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include "Sensor.hpp"

template <typename SensorTemplate>
class Server
{
private:
    static int serverCount;
    bool consolActivation;
    bool logActivation;
    std::string name;

public:
    Server();
    Server(const Server &other);
    Server(bool boolConsolActivation, bool boolLogActivation);
    Server &operator=(const Server &other);
    Server &operator<<(const Sensor<SensorTemplate> &other);
    ~Server();
    void consoleWrite(std::string message);
    void fileWrite(std::string sensorName, SensorTemplate sensorValue);
};

// Initialize static variable
template <typename SensorTemplate>
int Server<SensorTemplate>::serverCount = 0;

// Default constructor
template <typename SensorTemplate>
Server<SensorTemplate>::Server()
{   
    serverCount++;
    consolActivation = false;
    logActivation = false;
    name = "Server" + std::to_string(serverCount);
    std::cout << "[Server] " + this->name + " created. Console : "+ std::to_string(consolActivation) + " Log : " + std::to_string(logActivation) << std::endl;
}

// Copy constructor
template <typename SensorTemplate>
Server<SensorTemplate>::Server(const Server &other)
{   
    serverCount++;
    consolActivation = other.consolActivation;
    logActivation = other.logActivation;
    name = "Server" + std::to_string(serverCount);
    std::cout << "[Server] " << name << " has been copied to Server " << other.name << std::endl;
}

// Setter constructor
template <typename SensorTemplate>
Server<SensorTemplate>::Server(bool boolConsolActivation, bool boolLogActivation)
{   
    serverCount++;
    consolActivation = boolConsolActivation;
    logActivation = boolLogActivation;
    name = "Server" + std::to_string(serverCount);
    std::cout << "[Server] " << name << " created. Console : "+ std::to_string(consolActivation) + " Log : " + std::to_string(logActivation) << std::endl;
}

// Copy assignment operator
template <typename SensorTemplate>
Server<SensorTemplate> &Server<SensorTemplate>::operator=(const Server &other)
{
    consolActivation = other.consolActivation;
    logActivation = other.logActivation;
    std::cout << "[Server] " << name << " has been assigned to Server " << other.name << std::endl;
    return *this;
}

// Operator overload
template <typename SensorTemplate>
Server<SensorTemplate> &Server<SensorTemplate>::operator<<(const Sensor<SensorTemplate> &other)
{
    std::cout << "[Server] " << name << " received " << other.getName() << " : " << other.getValue() << std::endl;
    std::stringstream ss;
    ss << other.getValue();
    std::string value = ss.str();
    consoleWrite(other.getName() + " : " + value);
    fileWrite(other.getName(), other.getValue());
    return *this;
}

// Destructor
template <typename SensorTemplate>
Server<SensorTemplate>::~Server()
{
    std::cout << "[Server] " + this->name + " destroyed" << std::endl;
}

// Write to console
template <typename SensorTemplate>
void Server<SensorTemplate>::consoleWrite(std::string message)
{
    if (consolActivation)
    {
        std::cout << "[Log] " << message << std::endl;
    }
}

// Write to file
template <typename SensorTemplate>
void Server<SensorTemplate>::fileWrite(std::string name, SensorTemplate value)
{
    if (logActivation)
    {
        std::ofstream file;
        file.open(name + ".txt", std::ios::app);
        if (file.is_open())
        {
            std::ostream &out = file;
            out << value << std::endl;
            file.close();
        }
    }
}

#endif