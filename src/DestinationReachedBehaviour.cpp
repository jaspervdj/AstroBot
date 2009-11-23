#include "DestinationReachedBehaviour.h"
#include "Map.h"
#include "Robot.h"

DestinationReachedBehaviour::DestinationReachedBehaviour()
{
}

DestinationReachedBehaviour::~DestinationReachedBehaviour()
{
}

void DestinationReachedBehaviour::action()
{
    getMap()->getRobot()->setDestinationReached(true);
}

void DestinationReachedBehaviour::destinationReached(
        const DestinationEvent &event)
{
    setActive(true);
}
