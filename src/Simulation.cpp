#include "Simulation.h"
#include "Map.h"
#include "Robot.h"

using namespace std;

Simulation::Simulation(const string &fileName)
{
    /* Load the map. */
    map = new Map(fileName);

    /* Initialize and set the robot. */
    robot = new Robot();
    map->setRobot(robot);
}

Simulation::~Simulation()
{
    delete map;
    delete robot;
}

void Simulation::run()
{
    //initialiseer Behaviours en EventListeners

    //registreer Behaviours en EventListeners

    //start Subsumption
    /*while(!r.getDestinationReached()) {
        m.refresh();

        Behaviour* b = r.getFirstActiveBehaviour();

        b->action();
    }*/
}
