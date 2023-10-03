#include <iostream>
#include <string>
#include <fstream>
#include "Server.hpp"

// Default constructor
template <typename SensorTemplate>
Server<SensorTemplate>::Server() {
    std::cout << "Server created" << std::endl;
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
Server<SensorTemplate> &Server<SensorTemplate>::operator<<(const Sensor<SensorTemplate> &other) {
    consoleWrite(other.getName() + " : " + other.getValue());
    fileWrite(other.getName(), other.getValue());
    return *this;
}

// Destructor
template <typename SensorTemplate>
Server<SensorTemplate>::~Server() {
    std::cout << "Server destroyed" << std::endl;
}

template <typename SensorTemplate>
void Server<SensorTemplate>::consoleWrite(std::string message) {
    std::cout << message << std::endl;
}

// Console write
template <typename SensorTemplate>
void Server<SensorTemplate>::fileWrite(std::string name, std::string value) {
    std::ofstream file("sensors.txt", std::ios::app);
    file << name << " : " << value << std::endl;
    file.close();
}

