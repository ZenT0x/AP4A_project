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
    
public:
    Server();
    Server(const Server &other);
    Server &operator=(const Server &other);
    Server &operator<<(const Sensor<SensorTemplate> &other);
    ~Server();
    void consoleWrite(std::string message);
    void fileWrite(std::string sensorName, SensorTemplate sensorValue);

};

// Default constructor
template <typename SensorTemplate>
Server<SensorTemplate>::Server() {
    std::cout << "Server " << typeid(*this).name() << " created" << std::endl;
}

// Copy constructor
template <typename SensorTemplate>
Server<SensorTemplate>::Server(const Server &other) {
    std::cout << "Server copied" << std::endl;
}

// Copy assignment operator
template <typename SensorTemplate>
Server<SensorTemplate> &Server<SensorTemplate>::operator=(const Server &other) {
    std::cout << "Server assigned" << std::endl;
    return *this;
}

// Operator overload
template <typename SensorTemplate>
Server<SensorTemplate>& Server<SensorTemplate>::operator<<(const Sensor<SensorTemplate>& other) {
    std::cout << "Server received " << other.getName() << " : " << other.getValue() << std::endl;
    std::stringstream ss;
    ss << other.getValue();
    std::string value = ss.str();
    consoleWrite(other.getName() + " : " + value);
    fileWrite(other.getName(), other.getValue());
    return *this;
}

// Destructor
template <typename SensorTemplate>
Server<SensorTemplate>::~Server() {
    std::cout << "Server destroyed" << std::endl;
}

// Write to console
template <typename SensorTemplate>
void Server<SensorTemplate>::consoleWrite(std::string message) {
    std::cout << message << std::endl;
}

// Write to file
template <typename SensorTemplate>
void Server<SensorTemplate>::fileWrite(std::string name, SensorTemplate value) {
    std::ofstream file;
    file.open("data.txt", std::ios::app);
    if (file.is_open()) {
        std::ostream& out = file;
        out << name << " : " << value << std::endl;
        file.close();
    }
}

#endif 