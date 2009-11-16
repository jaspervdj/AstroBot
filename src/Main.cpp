#include <iostream>
#include <stdlib.h>
#include <string>

#include "Map.h"
#include "Robot.h"

using namespace std;

void run(const string &fileName)
{
    /*Map m = Map(file_name);

    Robot r = Robot();
    m.setRobot(&r);

    //initialiseer Behaviours en EventListeners

    //registreer Behaviours en EventListeners

    //start Subsumption
    while(!r.getDestinationReached()) {
        m.refresh();

        Behaviour* b = r.getFirstActiveBehaviour();

        b->action();
    }*/
}

int main(int argc, char** argv)
{
    // verwacht fileName van de in te laden map als argument!
    run(string(argv[1]));
    return 0;
}