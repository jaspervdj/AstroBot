#include <iostream>
#include <stdlib.h>
#include <string>

#ifdef WIN32
#include <crtdbg.h>
#endif

#include "Simulation.h"

using namespace std;

int main(int argc, char** argv)
{
    if(argc != 2) {
        cerr << "Syntax: AstroBot <map>" << endl;
        return 1;
    } else {
        /* Expect a file name. */
        Simulation simulation(argv[1]);
        simulation.run();

        #ifdef WIN32
        _CrtDumpMemoryLeaks();
        #endif

        return 0;
    }
}
