#include "TurnBehaviour.h"
#include "Map.h"
#include "Robot.h"
#include "ObstacleEvent.h"
#include "Obstacle.h"
#include "Orientation.h"
#include "GUI.h"

TurnBehaviour::TurnBehaviour()
{
}

TurnBehaviour::~TurnBehaviour()
{
}

void TurnBehaviour::obstacleDetected(const ObstacleEvent &event)
{
    setActive(true);
}

void TurnBehaviour::noObstacle()
{
    setActive(false);
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
}
