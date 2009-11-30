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
        DestinationReachedBehaviour(Map *map, Robot *robot);

        /**
         * Destructor.
         */
        virtual ~DestinationReachedBehaviour();

        /* Implementation. */
        void action();

        /* Implementation. */
        void destinationReached(const DestinationEvent &event);
};

#endif
