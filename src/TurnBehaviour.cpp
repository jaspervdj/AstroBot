#include "TurnBehaviour.h"
#include "Robot.h"
#include "ObstacleEvent.h"
#include "Obstacle.h"
#include "Orientation.h"
#include "GUI.h"

TurnBehaviour::TurnBehaviour(Robot *robot) : Behaviour()
{
    this->robot = robot;
    active = false;
}

TurnBehaviour::~TurnBehaviour()
{
}

bool TurnBehaviour::isActive()
{
    return active;
}

void TurnBehaviour::obstacleDetected(const ObstacleEvent &event)
{
    active = true;
}

void TurnBehaviour::noObstacle()
{
    active = false;
}

void TurnBehaviour::action()
{
    Orientation next = (Orientation)
            ((robot->getOrientation() + 1) % ORIENTATION_SIZE);
    robot->setOrientation(next);
    GUI::show(GUI::ROTATE);
}
