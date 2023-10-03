#include <iostream>
#include "Sensor.hpp"


// Default constructor
template <typename SensorTemplate>
Sensor<SensorTemplate>::Sensor() {
    std::cout << "Sensor "+this->name+" created" << std::endl;
}

// Copy constructor
template <typename SensorTemplate>
Sensor<SensorTemplate>::Sensor(const Sensor &other) : name(other.name), value(other.value) {
    std::cout << "Sensor " << name << " has been copied to Sensor " << other.name << std::endl;
}

// Setter constructor
template <typename SensorTemplate>
Sensor<SensorTemplate>::Sensor(std::string name, SensorTemplate value) : name(name), value(value) {
    std::cout << "Sensor " << name << " created" << std::endl;
}
    
// Copy assignment operator
template <typename SensorTemplate>
Sensor<SensorTemplate> &Sensor<SensorTemplate>::operator=(const Sensor &other) {
    std::cout << "Sensor " << name << " has been assigned to Sensor " << other.name << std::endl;
    if (this != &other) {
        name = other.name;
        value = other.value;
    }
    return *this;
}

// Destructor
template <typename SensorTemplate>
Sensor<SensorTemplate>::~Sensor() {
    std::cout << "Sensor "+this->name+" destroyed" << std::endl;
}

// Getters
template <typename SensorTemplate>
std::string Sensor<SensorTemplate>::getName() {
    return name;
}
template <typename SensorTemplate>
std::string Sensor<SensorTemplate>::getValue() {
    return value;
}
