#ifndef SERVER_HPP
#define SERVER_HPP
#include "Sensor.hpp"

class Server
{
private:
    
public:
    Server();
    Server(const Server &other);
    Server &operator=(const Server &other);
    Server &operator<<(const Sensor &other);
    ~Server();
    void consoleWrite(std::string message);
    void fileWrite(std::string sensorName, std::string sensorValue);

};


#endif 