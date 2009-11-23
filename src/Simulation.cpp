#include "Simulation.h"
#include "GUI.h"
#include "Map.h"
#include "Robot.h"
#include "MoveBehaviour.h"
#include "TurnBehaviour.h"
#include "DestinationReachedBehaviour.h"

#include <iostream>

using namespace std;

Simulation::Simulation(const string &fileName)
{
    /* Load the map. */
    map = new Map(fileName);
    GUI::initialize(fileName);

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
    // initialiseer Behaviours en EventListeners
    DestinationReachedBehaviour destinationReachedBehaviour;
    MoveBehaviour moveBehaviour;
    TurnBehaviour turnBehaviour;

    // registreer Behaviours en EventListeners
    destinationReachedBehaviour.setMap(map);
    map->registerListener(&destinationReachedBehaviour);
    robot->registerBehaviour(&destinationReachedBehaviour);

    moveBehaviour.setMap(map);
    map->registerListener(&moveBehaviour);
    robot->registerBehaviour(&moveBehaviour);
    
    turnBehaviour.setMap(map);
    map->registerListener(&turnBehaviour);
    robot->registerBehaviour(&turnBehaviour);

    // start Subsumption
    while(!robot->isDestinationReached()) {
        map->refresh();
        Behaviour *behaviour = robot->getFirstActiveBehaviour();
        if(!behaviour)
            cerr << "No active behaviour!" << endl;
        else
            behaviour->action();
    }
}
