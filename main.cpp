/**
 * @file main.cpp
 * @brief Main entry point for the application.
 *
 * This file contains the main function, which is the entry point for the application.
 * It creates a Scheduler object and sets logging options based on command line arguments.
 */

#include <iostream>
#include "Scheduler.hpp"

using namespace std;

/**
 * @brief Main function
 *
 * This function is the entry point for the application. It creates a Scheduler object
 * and sets logging options based on command line arguments.
 *
 * @param argc The number of command line arguments.
 * @param argv An array containing the command line arguments.
 * @return 0 on successful execution.
 */
int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Error: Exactly three arguments that are either '0' or '1' must be provided.\n";
        return -1;
    }

    for (int i = 1; i < argc; i++)
    {
        if (std::string(argv[i]) != "0" && std::string(argv[i]) != "1")
        {
            std::cerr << "Error: Arguments must be either '0' or '1'.\n";
            return -1;
        }
    }

    bool MainLog = std::string(argv[1]) == "1";
    bool ServerLog = std::string(argv[2]) == "1";
    bool SensorLog = std::string(argv[3]) == "1";

    Scheduler scheduler(MainLog, SensorLog, ServerLog);
    return 0;
}