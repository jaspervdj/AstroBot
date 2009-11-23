#include "MoveBehaviour.h"
#include "Map.h"
#include "Robot.h"

#include <iostream>

using namespace std;

MoveBehaviour::MoveBehaviour()
{
}

MoveBehaviour::~MoveBehaviour()
{
}

void MoveBehaviour::obstacleDetected(const ObstacleEvent &event)
{
    cout << "MoveBehaviour: obstacle detected!" << endl;
    setActive(false);
}

void MoveBehaviour::noObstacle()
{
    cout << "MoveBehaviour: no obstacle detected!" << endl;
    setActive(true);
}

bool MoveBehaviour::isActive()
{
    cout << "MoveBehaviour: active? " << Behaviour::isActive() << endl;
    return Behaviour::isActive();
}

void MoveBehaviour::action()
{
    getMap()->move();
    cout << "Woot, moving" << endl;
}