#include "Server.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes the server with default values. The serverLog flag is set to false.
 */
Server::Server()
{
    serverLog = false;
}

/**
 * @brief Copy constructor.
 *
 * Creates a new server as a copy of an existing one. The serverLog flag is copied from the other server. If the serverLog flag of the other server is true, a message is printed to the console.
 *
 * @param other The server to copy.
 */
Server::Server(const Server &other)
{
    serverLog = other.serverLog;
    if (serverLog)
    {
        cout << "[Server] Server has been copied to new Server " << endl;
    }
}

/**
 * @brief Parameterized constructor.
 *
 * Initializes the server with the given serverLog flag. If the serverLog flag is true, a message is printed to the console.
 *
 * @param boolserverLog Flag indicating whether to log server messages.
 */
Server::Server(bool boolserverLog)
{
    serverLog = boolserverLog;
    if (serverLog)
    {
        cout << "[Server] created. Log : " + to_string(serverLog) << endl;
    }
}

/**
 * @brief Copy assignment operator.
 *
 * Assigns the values of an existing server to this server. The serverLog flag is copied from the other server. If the serverLog flag of the other server is true, a message is printed to the console.
 *
 * @param other The server to copy values from.
 * @return A reference to this server.
 */
Server &Server::operator=(const Server &other)
{
    serverLog = other.serverLog;
    if (other.serverLog)
    {
        cout << "[Server] Server has been assigned to new Server " << endl;
    }
    return *this;
}

/**
 * @brief Destructor.
 *
 * Destroys the server. If the serverLog flag is true, a message is printed to the console.
 */
Server::~Server()
{
    if (serverLog)
    {
        cout << "[Server] Server destroyed" << endl;
    }
}

/**
 * @brief Writes a message to the console.
 *
 * If the serverLog flag is true, the given message is printed to the console.
 *
 * @param message The message to write to the console.
 */
void Server::consoleWrite(string message)
{
    if (serverLog)
    {
        cout << "[Log] " << message << endl;
    }
}