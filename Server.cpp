#include <iostream>
#include <string>
#include <fstream>
#include "Server.hpp"

// Default constructor
Server::Server() {
    std::cout << "Server created" << std::endl;
}

// Copy constructor
Server::Server(const Server &other) {
    std::cout << "Server copied" << std::endl;
}

// Copy assignment operator
Server& Server::operator=(const Server &other) {
    std::cout << "Server assigned" << std::endl;
    return *this;
}

Server& Server::operator<<(const Sensor &other) {
    consoleWrite(const_cast<Sensor&>(other).getName() + " : " + const_cast<Sensor&>(other).getValue());
    fileWrite(const_cast<Sensor&>(other).getName(), const_cast<Sensor&>(other).getValue());
    return *this;
}

// Destructor
Server::~Server() {
    std::cout << "Server destroyed" << std::endl;
}

void Server::consoleWrite(std::string message) {
    std::cout << message << std::endl;
}

void Server::fileWrite(std::string sensorName, std::string sensorValue) {
    std::ofstream file;
    file.open(sensorName+"_log"+".txt", std::ios::app);
    file << sensorValue << std::endl;
    file.close();
}

