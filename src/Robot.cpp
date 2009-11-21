#include "Robot.h"
#include "Orientation.h"
#include "Cell.h"
#include "Behaviour.h"

using namespace std;

Robot::Robot()
{
    destinationReached = false;
    speed = 1;
    orientation = NORTH;
}

Robot::~Robot()
{
}

bool Robot::isDestinationReached() const
{
    return destinationReached;
}

void Robot::setDestinationReached(bool destinationReached)
{
    this->destinationReached = destinationReached;
}

int Robot::getSpeed() const
{
    return speed;
}

void Robot::setSpeed(int speed)
{
    this->speed = speed;
}

Orientation Robot::getOrientation() const
{
    return orientation;
}

void Robot::setOrientation(Orientation orientation)
{
    this->orientation = orientation;
}

Cell *Robot::getCurrentPosition()
{
    return &position;
}

void Robot::setCurrentPosition(Cell *position)
{
    this->position = *position;
}

void Robot::addNextMove(Cell cell)
{
    path.push_back(&cell);
    setCurrentPosition(&cell);
}

void Robot::registerBehaviour(Behaviour *behaviour)
{
    behaviours.push_back(behaviour);
    behaviour->setRobot(this);
}

Behaviour *Robot::getFirstActiveBehaviour()
{
    list<Behaviour*>::iterator behaviour = behaviours.begin();

    while(behaviour != behaviours.end() && !(*behaviour)->isActive()) {
        behaviour++;
    }

    return *behaviour;
}
