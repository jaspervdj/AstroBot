#include "DestinationReachedBehaviour.h"
#include "Robot.h"

DestinationReachedBehaviour::DestinationReachedBehaviour(Robot *robot)
        : Behaviour()
{
    this->robot = robot;
    active = false;
}

DestinationReachedBehaviour::~DestinationReachedBehaviour()
{
}

bool DestinationReachedBehaviour::isActive()
{
    return active;
}

void DestinationReachedBehaviour::destinationReached(
        const DestinationEvent &event)
{
    active = true;
}

void DestinationReachedBehaviour::action()
{
    robot->setDestinationReached(true);
}
