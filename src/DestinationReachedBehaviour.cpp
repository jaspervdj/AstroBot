#include "DestinationReachedBehaviour.h"
#include "Map.h"
#include "Robot.h"

DestinationReachedBehaviour::DestinationReachedBehaviour()
{
    reached = false;
}

DestinationReachedBehaviour::~DestinationReachedBehaviour()
{
}

bool DestinationReachedBehaviour::isActive()
{
    return reached;
}

void DestinationReachedBehaviour::action()
{
    getMap()->getRobot()->setDestinationReached(true);
}

void DestinationReachedBehaviour::destinationReached(
        const DestinationEvent &event)
{
    reached = true;
}
