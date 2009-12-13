/**
 * Pieter De Baets
 * Jasper Van der Jeugt
 * Groep 31
 * DestinationEvent.cpp
 */
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
