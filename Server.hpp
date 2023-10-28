#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include "Sensor.hpp"

using namespace std;

template <typename SensorTemplate>
class Server
{
private:
    static int serverCount;
    bool serverLog;
    string name;

public:
    Server();
    Server(const Server &other);
    Server(bool boolserverLog);
    Server &operator=(const Server &other);
    Server &operator<<(const Sensor<SensorTemplate> &other);
    ~Server();
    void consoleWrite(string message);
    void fileWrite(string sensorName, SensorTemplate sensorValue);
};

// Initialize static variable
template <typename SensorTemplate>
int Server<SensorTemplate>::serverCount = 0;

// Default constructor
template <typename SensorTemplate>
Server<SensorTemplate>::Server()
{
    serverCount++;
    serverLog = false;
    name = "Server" + to_string(serverCount);
}

// Copy constructor
template <typename SensorTemplate>
Server<SensorTemplate>::Server(const Server &other)
{
    serverCount++;
    serverLog = other.serverLog;
    name = "Server" + to_string(serverCount);
    if (serverLog)
    {
        cout << "[Server] " << name << " has been copied to Server " << other.name << endl;
    }
}

// Setter constructor
template <typename SensorTemplate>
Server<SensorTemplate>::Server(bool boolserverLog)
{
    serverCount++;
    serverLog = boolserverLog;
    name = "Server" + to_string(serverCount);
    if (serverLog)
    {
        cout << "[Server] " << name << " created. Log : " + to_string(serverLog) << endl;
    }
}

// Copy assignment operator
template <typename SensorTemplate>
Server<SensorTemplate> &Server<SensorTemplate>::operator=(const Server &other)
{
    serverLog = other.serverLog;
    if (other.serverLog)
    {
        cout << "[Server] " << name << " has been assigned to Server " << other.name << endl;
    }
    return *this;
}

// Operator overload
template <typename SensorTemplate>
Server<SensorTemplate> &Server<SensorTemplate>::operator<<(const Sensor<SensorTemplate> &other)
{
    if (serverLog)
    {
        cout << "[Server] " << name << " received " << other.getName() << " : " << other.getValue() << endl;
    }
    stringstream ss;
    ss << other.getValue();
    string value = ss.str();
    consoleWrite(other.getName() + " : " + value);
    fileWrite(other.getName(), other.getValue());
    return *this;
}

// Destructor
template <typename SensorTemplate>
Server<SensorTemplate>::~Server()
{
    if (serverLog)
    {
        cout << "[Server] " + this->name + " destroyed" << endl;
    }
}

// Write to console
template <typename SensorTemplate>
void Server<SensorTemplate>::consoleWrite(string message)
{
    if (serverLog)
    {
        cout << "[Log] " << message << endl;
    }
}

// Write to file
template <typename SensorTemplate>
void Server<SensorTemplate>::fileWrite(string name, SensorTemplate value)
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

class ServerInt : public Server<int>
{
    public:
        ServerInt() : Server<int>() {}
        ServerInt(const ServerInt &other) : Server<int>(other) {}
        ServerInt(bool boolserverLog) : Server<int>(boolserverLog) {}
};

class ServerFloat : public Server<float>
{
    public:
        ServerFloat() : Server<float>() {}
        ServerFloat(const ServerFloat &other) : Server<float>(other) {}
        ServerFloat(bool boolserverLog) : Server<float>(boolserverLog) {}
};

class ServerDouble : public Server<double>
{
    public:
        ServerDouble() : Server<double>() {}
        ServerDouble(const ServerDouble &other) : Server<double>(other) {}
        ServerDouble(bool boolserverLog) : Server<double>(boolserverLog) {}
};

class ServerBool : public Server<bool>
{
    public:
        ServerBool() : Server<bool>() {}
        ServerBool(const ServerBool &other) : Server<bool>(other) {}
        ServerBool(bool boolserverLog) : Server<bool>(boolserverLog) {}
};



#endif