/**
 * Pieter De Baets
 * Jasper Van der Jeugt
 * Groep 31
 * DestinationReachedBehaviour.h
 */
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
        DestinationReachedBehaviour(Robot *robot);

        /**
         * Destructor.
         */
        virtual ~DestinationReachedBehaviour();

        /* Implementation. */
        bool isActive();

        /* Implementation. */
        void destinationReached(const DestinationEvent &event);

        /* Implementation. */
        void action();

     private:
        /** Robot to control. */
        Robot *robot;
    
        /** Flag to see if this behaviour is active. */
        bool active;
};

#endif
