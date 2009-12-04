#include "Simulation.h"
#include "GUI.h"
#include "Map.h"
#include "Robot.h"
#include "JumpBehaviour.h"
#include "MoveBehaviour.h"
#include "ShootBehaviour.h"
#include "BadnessBehaviour.h"
#include "TurnBehaviour.h"
#include "DestinationReachedBehaviour.h"

#include <iostream>
#include <exception>

using namespace std;

Simulation::Simulation(const string &fileName)
{
    /* Load the map. */
    map = new Map(fileName);
    GUI::initialize(fileName);

    /* Initialize and set the robot. */
    robot = new Robot();
    robot->setSpeed(1);    
    map->setRobot(robot);
}

Simulation::~Simulation()
{
    delete map;
    delete robot;
}

void Simulation::run()
{
    /* Create behaviours. */
    const int numberOfBehaviours = 5;
    Behaviour *behaviours[numberOfBehaviours] = {
        new DestinationReachedBehaviour(map, robot),
        new JumpBehaviour(map, robot),
        new ShootBehaviour(map, robot),
  //      new BadnessBehaviour(map, robot),
        new MoveBehaviour(map, robot),
        new TurnBehaviour(map, robot)
    };

    /* Initialize behaviours. */
    for(int i = 0; i < numberOfBehaviours; i++) {
        map->registerListener(behaviours[i]);
        robot->registerBehaviour(behaviours[i]);
    }

    /* Run subsumption. */
    while(!robot->isDestinationReached()) {
        map->refresh();
        Behaviour *behaviour = robot->getFirstActiveBehaviour();
        if(behaviour) {
            behaviour->action();
        } else {
            class NoActiveBehaviourException: public exception
            {
                const char *what()
                {
                    return "No active behaviour found.";
                }
            };

            throw NoActiveBehaviourException();
        }
    }

    /* Free behaviours. */
    for(int i = 0; i < numberOfBehaviours; i++) {
        delete behaviours[i];
    }
}
