#ifndef DESTINATIONEVENT_H
#define DESTINATIONEVENT_H

#include "Event.h"

class Cell;

class DestinationEvent: public Event
{
    public:
        /**
         * Constructor.
         * @param destination The reached destination.
         */
        DestinationEvent(Cell *destination);

        /**
         * Destructor.
         */
        ~DestinationEvent();

        /**
         * Get the reached destination.
         * @return The destination reached.
         */
        Cell *getDestination() const;

    private:
        /** The reached destination. */
        Cell *destination;
};

#endif
