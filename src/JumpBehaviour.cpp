#include "JumpBehaviour.h"
#include "Map.h"
#include "Robot.h"
#include "Obstacle.h"

#include <iostream>

using namespace std;

JumpBehaviour::JumpBehaviour()
{
}

JumpBehaviour::~JumpBehaviour()
{
}

void JumpBehaviour::obstacleDetected(const ObstacleEvent &event)
{
    cout << "MoveBehaviour: obstacle detected!" << endl;
    setActive(event.getObstacle()->isJumpable());
}

void JumpBehaviour::noObstacle()
{
    cout << "JumpBehaviour: no obstacle detected!" << endl;
    setActive(false);
}

bool JumpBehaviour::isActive()
{
    cout << "JumpBehaviour: active? " << Behaviour::isActive() << endl;
    return Behaviour::isActive();
}

void JumpBehaviour::action()
{
    getMap()->jump();
    cout << "Woot, jumping" << endl;
}
