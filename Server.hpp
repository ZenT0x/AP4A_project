/**
 * @file Server.hpp
 * @brief Server class definition.
 *
 * This file contains the definition of the Server class, which is responsible for
 * managing and logging sensor data.
 */

#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include "Sensor.hpp"

using namespace std;

/**
 * @class Server
 * @brief Server class.
 *
 * This class is responsible for managing and logging sensor data.
 */
class Server
{
private:
    /**
     * @brief Flag indicating whether to log server messages.
     */
    bool serverLog;
    /**
     * @brief Writes a message to the console.
     *
     * If the serverLog flag is true, the given message is printed to the console.
     *
     * @param message The message to write to the console.
     */
    void consoleWrite(string message);

    /**
     * @brief Writes sensor data to a file.
     *
     * If the serverLog flag is true, the sensor data is written to a file.
     *
     * @param sensorName The name of the sensor.
     * @param sensorValue The value of the sensor.
     */
    template <typename SensorTemplate>
    void fileWrite(string sensorName, SensorTemplate sensorValue);

public:
    /**
     * @brief Default constructor.
     *
     * Initializes the server with default values.
     */
    Server();

    /**
     * @brief Copy constructor.
     *
     * Creates a new server as a copy of an existing one.
     *
     * @param other The server to copy.
     */
    Server(const Server &other);

    /**
     * @brief Parameterized constructor.
     *
     * Initializes the server with the given serverLog flag.
     *
     * @param boolserverLog Flag indicating whether to log server messages.
     */
    Server(bool boolserverLog);

    /**
     * @brief Copy assignment operator.
     *
     * Assigns the values of an existing server to this server.
     *
     * @param other The server to copy values from.
     * @return A reference to this server.
     */
    Server &operator=(const Server &other);

    /**
     * @brief Overloaded insertion operator.
     *
     * Logs the sensor data to the server.
     *
     * @param other The sensor to log data from.
     * @return A reference to this server.
     */
    template <typename SensorTemplate>
    Server &operator<<(const Sensor<SensorTemplate> &other);

    /**
     * @brief Destructor.
     *
     * Destroys the server.
     */
    ~Server();
};

/**
 * @brief Overloaded insertion operator.
 *
 * Logs the sensor data to the server. If the serverLog flag is true, the sensor's name and value are printed to the console. The sensor's name and value are also written to the console and to a file.
 *
 * @param other The sensor to log data from.
 * @return A reference to this server.
 */
template <typename SensorTemplate>
Server &Server::operator<<(const Sensor<SensorTemplate> &other)
{
    if (serverLog)
    {
        cout << "[Server] received " << other.getName() << " : " << other.getValue() << endl;
    }
    stringstream ss;
    ss << other.getValue();
    string value = ss.str();
    consoleWrite(other.getName() + " : " + value);
    fileWrite(other.getName(), other.getValue());
    return *this;
}

/**
 * @brief Writes sensor data to a file.
 *
 * If the serverLog flag is true, the sensor data is written to a file. The file is named after the sensor and the data is appended to the file.
 *
 * @param name The name of the sensor.
 * @param value The value of the sensor.
 */
template <typename SensorTemplate>
void Server::fileWrite(string name, SensorTemplate value)
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

#endif