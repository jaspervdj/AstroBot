#include "DestinationEvent.h"
#include "Cell.h"

DestinationEvent::DestinationEvent(Cell *destination)
{
    this->destination = destination;
}

DestinationEvent::~DestinationEvent()
{
}

Cell *DestinationEvent::getDestination() const
{
    return destination;
}
