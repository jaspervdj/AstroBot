/**
 * Pieter De Baets
 * Jasper Van der Jeugt
 * Groep 31
 * Behaviour.h
 */
#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

class Map;
class Robot;

#include "EventListener.h"

/** Abstract class defining a certain Robot behaviour. */
class Behaviour: public EventListener
{
    public:
        /**
         * Constructor.
         */
        Behaviour();

        /**
         * Destructor.
         */
        virtual ~Behaviour();

        /**
         * Check if this Robot behaviour wants focus.
         * @return If this robot behaviour wants focus.
         */
        virtual bool isActive() = 0;

        /**
         * Execute the behaviour action.
         */
        virtual void action() = 0;
};

#endif
