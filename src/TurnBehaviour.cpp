#include "TurnBehaviour.h"
#include "Map.h"
#include "Robot.h"
#include "ObstacleEvent.h"
#include "Obstacle.h"

#include <iostream>

using namespace std;

TurnBehaviour::TurnBehaviour()
{
}

TurnBehaviour::~TurnBehaviour()
{
}

void TurnBehaviour::obstacleDetected(const ObstacleEvent &event)
{
    const Obstacle *obstacle = event.getObstacle();
    cout << "TurnBehaviour: obstacle detected!" << endl;
    setActive(!obstacle->isJumpable() && !obstacle->isShootable());
}

void TurnBehaviour::noObstacle()
{
    cout << "TurnBehaviour: no obstacle detected!" << endl;
    setActive(false);
}

bool TurnBehaviour::isActive()
{
    cout << "TurnBehaviour: active? " << Behaviour::isActive() << endl;
    return Behaviour::isActive();
}

void TurnBehaviour::action()
{
    cout << "Woot, moving" << endl;
}