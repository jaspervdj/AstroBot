#include "TurnBehaviour.h"
#include "Map.h"
#include "Robot.h"
#include "ObstacleEvent.h"
#include "Obstacle.h"
#include "Orientation.h"
#include "GUI.h"

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
    setActive(true);
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
    Orientation current = getMap()->getRobot()->getOrientation();

    Orientation next;
    if(current == NORTH) next = EAST;
    else if(current == EAST) next = SOUTH;
    else if(current == SOUTH) next = WEST;
    else if(current == WEST) next = NORTH;

    getMap()->getRobot()->setOrientation(next);
    GUI::show(GUI::ROTATE);

    cout << "Woot, turning" << endl;
}
