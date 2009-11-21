#include "Simulation.h"
#include "Map.h"
#include "Robot.h"
#include "DestinationReachedBehaviour.h"

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
    DestinationReachedBehaviour destinationReachedBehaviour;
    map->registerListener(&destinationReachedBehaviour);
    robot->registerBehaviour(&destinationReachedBehaviour);
    //initialiseer Behaviours en EventListeners

    //registreer Behaviours en EventListeners

    /* start Subsumption */
    /* while(!robot->isDestinationReached()) {
        map->refresh();
        Behaviour *behaviour = robot->getFirstActiveBehaviour();
        behaviour->action();
    } */
}
