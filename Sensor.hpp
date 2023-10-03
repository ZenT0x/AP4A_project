#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <string>


class Sensor
{
private:
    std::string name;
    std::string value;
public:
    Sensor();
    Sensor(const Sensor &other);
    Sensor(std::string name, std::string value);
    Sensor &operator=(const Sensor &other);
    ~Sensor();
    std::string getName();
    std::string getValue();
};





#endif