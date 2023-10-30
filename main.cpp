#include <iostream>
#include "Scheduler.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    bool MainLog = false;
    bool ServerLog = false;
    bool SensorLog = false;
    
    srand(time(NULL));

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
    scheduler.run();
    return 0;
}


