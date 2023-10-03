#include <iostream>
#include "Sensor.hpp"


// Default constructor
Sensor::Sensor() {
    std::cout << "Sensor "+this->name+" created" << std::endl;
}

// Copy constructor
Sensor::Sensor(const Sensor &other) {
    std::cout << "Sensor "+this->name+" has been copied to Sensor "+other.name << std::endl;
}

// Setter constructor
Sensor::Sensor(std::string name, std::string value) {
    this->name = name;
    this->value = value;
    std::cout << "Sensor "+this->name+" created" << std::endl;
}
    
// Copy assignment operator
Sensor& Sensor::operator=(const Sensor &other) {
    std::cout << "Sensor "+this->name+" has been assigned to Sensor "+other.name << std::endl;
    this->name = other.name;
    this->value = other.value;
    return *this;
}

// Destructor
Sensor::~Sensor() {
    std::cout << "Sensor "+this->name+" destroyed" << std::endl;
}

// Getters
std::string Sensor::getName() {
    return name;
}
std::string Sensor::getValue() {
    return value;
}
