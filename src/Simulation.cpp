#include "Simulation.h"
#include "GUI.h"
#include "Map.h"
#include "Robot.h"
#include "MoveBehaviour.h"
#include "DestinationReachedBehaviour.h"

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
    MoveBehaviour moveBehaviour;
    DestinationReachedBehaviour destinationReachedBehaviour;

    // registreer Behaviours en EventListeners
    moveBehaviour.setMap(map);
    map->registerListener(&moveBehaviour);
    robot->registerBehaviour(&moveBehaviour);
    
    destinationReachedBehaviour.setMap(map);
    map->registerListener(&destinationReachedBehaviour);
    robot->registerBehaviour(&destinationReachedBehaviour);

    // start Subsumption
    while(!robot->isDestinationReached()) {
        map->refresh();
        Behaviour *behaviour = robot->getFirstActiveBehaviour();
        behaviour->action();
    }
}
