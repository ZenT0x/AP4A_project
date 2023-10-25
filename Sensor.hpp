#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <iostream>
#include <string>
#include <cstdlib>

template <typename SensorTemplate>
class Sensor
{
private:
    static int sensorCount;
    std::string name;
    SensorTemplate value;

public:
    Sensor();
    Sensor(const Sensor &other);
    Sensor(std::string name, SensorTemplate value);
    Sensor &operator=(const Sensor &other);
    ~Sensor();
    std::string getName() const;
    SensorTemplate getValue() const;
    SensorTemplate aleaGenVal();
};

// Initialize static variable
template <typename SensorTemplate>
int Sensor<SensorTemplate>::sensorCount = 0;

// Default constructor
template <typename SensorTemplate>
Sensor<SensorTemplate>::Sensor()
{
    std::cout << "[Sensor] " + this->name + " created" << std::endl;
}

// Copy constructor
template <typename SensorTemplate>
Sensor<SensorTemplate>::Sensor(const Sensor &other) : name(other.name), value(other.value)
{
    std::cout << "[Sensor] " << name << " has been copied to Sensor " << other.name << std::endl;
}

// Setter constructor
template <typename SensorTemplate>
Sensor<SensorTemplate>::Sensor(std::string name, SensorTemplate value) : name(name), value(value)
{
    std::cout << "[Sensor] " << name << " created" << std::endl;
}

// Copy assignment operator
template <typename SensorTemplate>
Sensor<SensorTemplate> &Sensor<SensorTemplate>::operator=(const Sensor &other)
{
    std::cout << "[Sensor] " << name << " has been assigned to Sensor " << other.name << std::endl;
    if (this != &other)
    {
        name = other.name;
        value = other.value;
    }
    return *this;
}

// Destructor
template <typename SensorTemplate>
Sensor<SensorTemplate>::~Sensor()
{
    std::cout << "[Sensor] " + this->name + " destroyed" << std::endl;
}

// Getters
template <typename SensorTemplate>
std::string Sensor<SensorTemplate>::getName() const
{
    return name;
}
template <typename SensorTemplate>
SensorTemplate Sensor<SensorTemplate>::getValue() const
{
    return value;
}

#endif