#include "Simulation.h"
#include "Map.h"
#include "Robot.h"
#include "DestinationReachedBehaviour.h"
#include <iostream>

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
    DestinationReachedBehaviour destinationReachedBehaviour;

    //registreer Behaviours en EventListeners
    map->registerListener(&destinationReachedBehaviour);
    robot->registerBehaviour(&destinationReachedBehaviour);

    /* start Subsumption */
    /* while(!robot->isDestinationReached()) {
        map->refresh();
        Behaviour *behaviour = robot->getFirstActiveBehaviour();
        behaviour->action();
    } */
}
