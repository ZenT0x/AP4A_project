#include "Server.hpp"

// Default constructor
Server::Server()
{
    serverLog = false;
}

// Copy constructor
Server::Server(const Server &other)
{
    serverLog = other.serverLog;
    if (serverLog)
    {
        cout << "[Server] Server has been copied to new Server " << endl;
    }
}

// Setter constructor
Server::Server(bool boolserverLog)
{
    serverLog = boolserverLog;
    if (serverLog)
    {
        cout << "[Server] created. Log : " + to_string(serverLog) << endl;
    }
}

// Copy assignment operator
Server &Server::operator=(const Server &other)
{
    serverLog = other.serverLog;
    if (other.serverLog)
    {
        cout << "[Server] Server has been assigned to new Server " << endl;
    }
    return *this;
}

// Destructor
Server::~Server()
{
    if (serverLog)
    {
        cout << "[Server] Server destroyed" << endl;
    }
}

// Write to console
void Server::consoleWrite(string message)
{
    if (serverLog)
    {
        cout << "[Log] " << message << endl;
    }
}

