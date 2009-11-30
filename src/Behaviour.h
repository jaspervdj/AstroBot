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
         * @param map Map the robot is in.
         * @param robot Robot to control.
         */
        Behaviour(Map *map, Robot *robot);

        /**
         * Destructor.
         */
        virtual ~Behaviour();

        /**
         * Check if this Robot behaviour wants focus.
         * @return If this robot behaviour wants focus.
         */
        virtual bool isActive();

        /**
         * Execute the behaviour action.
         */
        virtual void action() = 0;

    protected:
        /**
         * Mark the current behaviour as active
         */
        void setActive(bool active);

        /** Map the robot is on. */
        Map *map;

        /** Robot to control. */
        Robot *robot;

    private:
        /** Flag to see if this behaviour is active. */
        bool active;
};

#endif
