#include "DestinationReachedBehaviour.h"
#include "Map.h"
#include "Robot.h"

DestinationReachedBehaviour::DestinationReachedBehaviour(Map *map, Robot *robot)
        : Behaviour(map, robot)
{
}

DestinationReachedBehaviour::~DestinationReachedBehaviour()
{
}

void DestinationReachedBehaviour::destinationReached(
        const DestinationEvent &event)
{
    setActive(true);
}

void DestinationReachedBehaviour::action()
{
    robot->setDestinationReached(true);
}
