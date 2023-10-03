#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <string>

template <typename SensorTemplate>
class Sensor
{
private:
    std::string name;
    SensorTemplate value;
public:
    Sensor();
    Sensor(const Sensor &other);
    Sensor(std::string name, SensorTemplate value);
    Sensor &operator=(const Sensor &other);
    ~Sensor();
    std::string getName();
    std::string getValue();
};





#endif