#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include "Sensor.hpp"

using namespace std;


class Server
{
private:
    bool serverLog;

public:
    Server();
    Server(const Server &other);
    Server(bool boolserverLog);
    Server &operator=(const Server &other);
    template <typename SensorTemplate>
    Server &operator<<(const Sensor<SensorTemplate> &other);
    ~Server();
    void consoleWrite(string message);
    template <typename SensorTemplate>
    void fileWrite(string sensorName, SensorTemplate sensorValue);
};

// Operator overload
template <typename SensorTemplate>
Server &Server::operator<<(const Sensor<SensorTemplate> &other)
{
    if (serverLog)
    {
        cout << "[Server] received " << other.getName() << " : " << other.getValue() << endl;
    }
    stringstream ss;
    ss << other.getValue();
    string value = ss.str();
    consoleWrite(other.getName() + " : " + value);
    fileWrite(other.getName(), other.getValue());
    return *this;
}

// Write to file
template <typename SensorTemplate>
void Server::fileWrite(string name, SensorTemplate value)
{
    if (serverLog)
    {
        ofstream file;
        file.open(name + ".txt", ios::app);
        if (file.is_open())
        {
            ostream &out = file;
            out << value << endl;
            file.close();
        }
    }
}

#endif