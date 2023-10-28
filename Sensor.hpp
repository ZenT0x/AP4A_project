#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <random>

using namespace std;
template <typename SensorTemplate>
class Sensor
{
private:
    static int sensorCount;
    string name;
    bool sensorLog;
    SensorTemplate value;

public:
    Sensor();
    Sensor(const Sensor &other);
    Sensor(string name, SensorTemplate value, bool boolSensorLog);
    Sensor &operator=(const Sensor &other);
    ~Sensor();
    string getName() const;
    SensorTemplate getValue() const;
    SensorTemplate aleaGenVal();
};

// Initialize static variable
template <typename SensorTemplate>
int Sensor<SensorTemplate>::sensorCount = 0;

// Default constructor
template <typename SensorTemplate>
Sensor<SensorTemplate>::Sensor() : name("Sensor" + to_string(sensorCount)), sensorLog(false), value(0)
{
    sensorCount++;   
}


// Copy constructor
template <typename SensorTemplate>
Sensor<SensorTemplate>::Sensor(const Sensor &other) : name(other.name), value(other.value), sensorLog(other.sensorLog)
{
    if (other.sensorLog)
    {
        cout << "[Sensor] " << name << " has been copied to Sensor " << other.name << endl;
    }
}
// Setter constructor
template <typename SensorTemplate>
Sensor<SensorTemplate>::Sensor(string name, SensorTemplate value, bool boolSensorLog) : name(name), value(value), sensorLog(boolSensorLog)
{
    if (sensorLog)
    {
        cout << "[Sensor] " << name << " created" << endl;
    }
}

// Copy assignment operator
template <typename SensorTemplate>
Sensor<SensorTemplate> &Sensor<SensorTemplate>::operator=(const Sensor &other)
{
    if (sensorLog)
    {
        cout << "[Sensor] " << name << " has been assigned to Sensor " << other.name << endl;
    }
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
    if (sensorLog)
    {
        cout << "[Sensor] " + this->name + " destroyed" << endl;
    }
}

// Getters
template <typename SensorTemplate>
string Sensor<SensorTemplate>::getName() const
{
    return name;
}
template <typename SensorTemplate>
SensorTemplate Sensor<SensorTemplate>::getValue() const
{
    return value;

}

// Generate random value based on sensor type
template <typename SensorTemplate>
SensorTemplate Sensor<SensorTemplate>::aleaGenVal()
{   
    random_device rand;
    mt19937 gen(rand());
    
    if (is_same<SensorTemplate, int>::value)
    {
        uniform_int_distribution<int> dist(15, 40);
        value = dist(gen);
    }
    else if (is_same<SensorTemplate, float>::value)
    {
        uniform_real_distribution<float> dist(40, 110.0);
        value = dist(gen);
    }
    else if (is_same<SensorTemplate, double>::value)
    {
        uniform_real_distribution<double> dist(200.0, 3000.0);
        value = dist(gen);
    }
    else if (is_same<SensorTemplate, bool>::value)
    {
        uniform_int_distribution<int> dist(0, 1);
        value = dist(gen);
    }
    else
    {
        // Unsupported sensor type
        throw invalid_argument("Unsupported sensor type");
    }
    if (sensorLog)
    {
        cout << "[Sensor] " << name << " value is " << value << endl;
    }
    return value;
}

class SensorInt : public Sensor<int>
{
    public:
        SensorInt() : Sensor<int>() {}
        SensorInt(const SensorInt &other) : Sensor<int>(other) {}
        SensorInt(string name, int value, bool boolSensorLog) : Sensor<int>(name, value, boolSensorLog) {}
};

class SensorFloat : public Sensor<float>
{
    public:
        SensorFloat() : Sensor<float>() {}
        SensorFloat(const SensorFloat &other) : Sensor<float>(other) {}
        SensorFloat(string name, float value, bool boolSensorLog) : Sensor<float>(name, value, boolSensorLog) {}
};

class SensorDouble : public Sensor<double>
{
    public:
        SensorDouble() : Sensor<double>() {}
        SensorDouble(const SensorDouble &other) : Sensor<double>(other) {}
        SensorDouble(string name, double value, bool boolSensorLog) : Sensor<double>(name, value, boolSensorLog) {}
};

class SensorBool : public Sensor<bool>
{
    public:
        SensorBool() : Sensor<bool>() {}
        SensorBool(const SensorBool &other) : Sensor<bool>(other) {}
        SensorBool(string name, bool value, bool boolSensorLog) : Sensor<bool>(name, value, boolSensorLog) {}
};



#endif
