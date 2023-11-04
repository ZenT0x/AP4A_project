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
    bool MainLog = false;
    bool ServerLog = false;
    bool SensorLog = false;

    if (argc > 1)
    {   
        if (string(argv[1]) == "1")
        {
            MainLog = true;
        }
        if (string(argv[2]) == "1")
        {
            ServerLog = true;
        }
        if (string(argv[3]) == "1")
        {
           SensorLog = true;
        }
        
    }
    Scheduler scheduler(MainLog, SensorLog, ServerLog);
    return 0;
}