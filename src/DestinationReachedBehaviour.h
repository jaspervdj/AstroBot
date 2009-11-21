#ifndef DESTINATIONREACHEDBEHAVIOUR_H
#define DESTINATIONREACHEDBEHAVIOUR_H

#include "Behaviour.h"
#include "DestinationEventListener.h"

/**
 * Behaviour that reacts when the destination is reached.
 */
class DestinationReachedBehaviour: public Behaviour,
        public DestinationEventListener
{
    public:
        /**
         * Constructor.
         */
        DestinationReachedBehaviour();

        /**
         * Destructor.
         */
        virtual ~DestinationReachedBehaviour();

        /* Implementation. */
        bool isActive();

        /* Implementation. */
        void action();

        /* Implementation. */
        void destinationReached(const DestinationEvent &event);

    private:
        /** Flag to see if we reached the destination. */
        bool reached;
};

#endif
