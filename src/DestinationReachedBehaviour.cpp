#include "DestinationReachedBehaviour.h"
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
    getRobot()->setDestinationReached(true);
}

void DestinationReachedBehaviour::destinationReached(
        const DestinationEvent &event)
{
    reached = true;
}
