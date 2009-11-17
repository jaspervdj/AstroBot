#ifndef DESTINATIONEVENTLISTENER_H
#define DESTINATIONEVENTLISTENER_H

#include "DestinationEvent.h"
#include "EventListener.h"

class DestinationEventListener: public EventListener
{
    public:
        /**
         * Constructor.
         */
        DestinationEventListener();

        /**
         * Destructor.
         */
        ~DestinationEventListener();

        /**
         * Called when destination is reached.
         * @param event Event containing more information.
         */
        virtual void destinationReached(const DestinationEvent &event) = 0;
};

#endif
