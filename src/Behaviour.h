#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

class Map;

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
        virtual bool isActive();

        /**
         * Execute the behaviour action.
         */
        virtual void action() = 0;

        /**
         * Get the map for the robot.
         * @return The map this robot is on.
         */
        Map *getMap() const;

        /**
         * Set the map the robot is on.
         * @param map Map the robot is on.
         */
        void setMap(Map *map);
        
    protected:
        /**
         * Mark the current behaviour as active
         */
        void setActive(bool active);

    private:
        /** Map the robot is on. */
        Map *map;

        /** Flag to see if this behaviour is active. */
        bool active;
};

#endif
