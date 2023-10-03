#ifndef SERVER_HPP
#define SERVER_HPP
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
    void fileWrite(std::string sensorName, std::string value);

};


#endif 