#ifndef OBSTACLEEVENT_H
#define OBSTACLEEVENT_H

#include "Event.h"

class Obstacle;

class ObstacleEvent: public Event
{
    public:
        /**
         * Constructor.
         */
        ObstacleEvent(Obstacle* obstacle);

        /**
         * Destructor.
         */
        ~ObstacleEvent();
        
        /**
         * Get obstacle we're currently looking at
         */
        Obstacle *getObstacle() const;
        
    private:
        /** Obstacle */
        Obstacle *obstacle;
};

#endif
