/**
 * @file Sensor.hpp
 * @brief Sensor class definition.
 *
 * This file contains the definition of the Sensor class, which is responsible for
 * generating and managing sensor data.
 */

#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/**
 * @class Sensor
 * @brief Sensor class.
 *
 * This class is responsible for generating and managing sensor data.
 */
template <typename SensorTemplate>
class Sensor
{
private:
    string name; ///< The name of the sensor.
    bool sensorLog; ///< Flag indicating whether to log sensor messages.
    SensorTemplate value; ///< The current value of the sensor.

public:
    /**
     * @brief Default constructor.
     *
     * Initializes the sensor with default values.
     */
    Sensor();

    /**
     * @brief Copy constructor.
     *
     * Creates a new sensor as a copy of an existing one.
     *
     * @param other The sensor to copy.
     */
    Sensor(const Sensor &other);

    /**
     * @brief Parameterized constructor.
     *
     * Initializes the sensor with the given values.
     *
     * @param name The name of the sensor.
     * @param value The initial value of the sensor.
     * @param boolSensorLog Flag indicating whether to log sensor messages.
     */
    Sensor(string name, SensorTemplate value, bool boolSensorLog);

    /**
     * @brief Copy assignment operator.
     *
     * Assigns the values of an existing sensor to this sensor.
     *
     * @param other The sensor to copy values from.
     * @return A reference to this sensor.
     */
    Sensor &operator=(const Sensor &other);

    /**
     * @brief Destructor.
     *
     * Destroys the sensor.
     */
    ~Sensor();

    /**
     * @brief Gets the name of the sensor.
     *
     * @return The name of the sensor.
     */
    string getName() const;

    /**
     * @brief Gets the current value of the sensor.
     *
     * @return The current value of the sensor.
     */
    SensorTemplate getValue() const;

    /**
     * @brief Generates a random value for the sensor.
     *
     * The type of value generated depends on the type of the sensor.
     *
     * @return The generated value.
     */
    SensorTemplate aleaGenVal();
};

/**
 * @brief Default constructor.
 *
 * Initializes the sensor with default values. The name is set to "Sensor", the sensorLog flag is set to false, and the value is set to 0.
 */
template <typename SensorTemplate>
Sensor<SensorTemplate>::Sensor() : name("Sensor"), sensorLog(false), value(0)
{

}

/**
 * @brief Copy constructor.
 *
 * Creates a new sensor as a copy of an existing one. The name, value, and sensorLog flag are copied from the other sensor. If the sensorLog flag of the other sensor is true, a message is printed to the console.
 *
 * @param other The sensor to copy.
 */
template <typename SensorTemplate>
Sensor<SensorTemplate>::Sensor(const Sensor &other) : name(other.name), value(other.value), sensorLog(other.sensorLog)
{   
    if (other.sensorLog)
    {
        cout << "[Sensor] " << name << " has been copied to Sensor " << other.name << endl;
    }
}

/**
 * @brief Parameterized constructor.
 *
 * Initializes the sensor with the given values. If the sensorLog flag is true, a message is printed to the console.
 *
 * @param name The name of the sensor.
 * @param value The initial value of the sensor.
 * @param boolSensorLog Flag indicating whether to log sensor messages.
 */
template <typename SensorTemplate>
Sensor<SensorTemplate>::Sensor(string name, SensorTemplate value, bool boolSensorLog) : name(name), value(value), sensorLog(boolSensorLog)
{   
    if (sensorLog)
    {
        cout << "[Sensor] " << name << " created" << endl;
    }
}

/**
 * @brief Copy assignment operator.
 *
 * Assigns the values of an existing sensor to this sensor. If the sensorLog flag is true, a message is printed to the console before the assignment is made. The name and value are copied from the other sensor.
 *
 * @param other The sensor to copy values from.
 * @return A reference to this sensor.
 */
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

/**
 * @brief Destructor.
 *
 * Destroys the sensor. If the sensorLog flag is true, a message is printed to the console.
 */
template <typename SensorTemplate>
Sensor<SensorTemplate>::~Sensor()
{
    if (sensorLog)
    {
        cout << "[Sensor] " + this->name + " destroyed" << endl;
    }
}

/**
 * @brief Gets the name of the sensor.
 *
 * @return The name of the sensor.
 */
template <typename SensorTemplate>
string Sensor<SensorTemplate>::getName() const
{
    return name;
}

/**
 * @brief Gets the current value of the sensor.
 *
 * @return The current value of the sensor.
 */
template <typename SensorTemplate>
SensorTemplate Sensor<SensorTemplate>::getValue() const
{
    return value;
}

/**
 * @brief Generates a random value for the sensor.
 *
 * The type of value generated depends on the type of the sensor. If the sensorLog flag is true, a message is printed to the console.
 *
 * @return The generated value.
 */
template <typename SensorTemplate>
SensorTemplate Sensor<SensorTemplate>::aleaGenVal()
{   

    if (is_same<SensorTemplate, int>::value)
    {
        value = rand() %71 + 40;
    }
    else if (is_same<SensorTemplate, float>::value)
    {
        value = rand() / static_cast<float>(RAND_MAX) * 30.4 + 10.5f;
    }
    else if (is_same<SensorTemplate, bool>::value)
    {
        value = rand() % 2;
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

/**
 * @class SensorInt
 * @brief SensorInt class.
 *
 * This class is a specialization of the Sensor class for integer values.
 */
class SensorInt : public Sensor<int>
{
public:
    /**
     * @brief Default constructor.
     *
     * Initializes the sensor with default values.
     */
    SensorInt() : Sensor<int>() {}

    /**
     * @brief Copy constructor.
     *
     * Creates a new sensor as a copy of an existing one.
     *
     * @param other The sensor to copy.
     */
    SensorInt(const SensorInt &other) : Sensor<int>(other) {}

    /**
     * @brief Parameterized constructor.
     *
     * Initializes the sensor with the given values.
     *
     * @param name The name of the sensor.
     * @param value The initial value of the sensor.
     * @param boolSensorLog Flag indicating whether to log sensor messages.
     */
    SensorInt(string name, int value, bool boolSensorLog) : Sensor<int>(name, value, boolSensorLog) {}
};


/**
 * @class SensorFloat
 * @brief SensorFloat class.
 *
 * This class is a specialization of the Sensor class for float values.
 */
class SensorFloat : public Sensor<float>
{
public:
    /**
     * @brief Default constructor.
     *
     * Initializes the sensor with default values.
     */
    SensorFloat() : Sensor<float>() {}

    /**
     * @brief Copy constructor.
     *
     * Creates a new sensor as a copy of an existing one.
     *
     * @param other The sensor to copy.
     */
    SensorFloat(const SensorFloat &other) : Sensor<float>(other) {}

    /**
     * @brief Parameterized constructor.
     *
     * Initializes the sensor with the given values.
     *
     * @param name The name of the sensor.
     * @param value The initial value of the sensor.
     * @param boolSensorLog Flag indicating whether to log sensor messages.
     */
    SensorFloat(string name, float value, bool boolSensorLog) : Sensor<float>(name, value, boolSensorLog) {}
};

/**
 * @class SensorBool
 * @brief SensorBool class.
 *
 * This class is a specialization of the Sensor class for boolean values.
 */
class SensorBool : public Sensor<bool>
{
public:
    /**
     * @brief Default constructor.
     *
     * Initializes the sensor with default values.
     */
    SensorBool() : Sensor<bool>() {}

    /**
     * @brief Copy constructor.
     *
     * Creates a new sensor as a copy of an existing one.
     *
     * @param other The sensor to copy.
     */
    SensorBool(const SensorBool &other) : Sensor<bool>(other) {}

    /**
     * @brief Parameterized constructor.
     *
     * Initializes the sensor with the given values.
     *
     * @param name The name of the sensor.
     * @param value The initial value of the sensor.
     * @param boolSensorLog Flag indicating whether to log sensor messages.
     */
    SensorBool(string name, bool value, bool boolSensorLog) : Sensor<bool>(name, value, boolSensorLog) {}
};

#endif