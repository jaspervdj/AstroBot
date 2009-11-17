#ifndef OBSTACLEEVENTLISTENER_H
#define OBSTACLEEVENTLISTENER_H

#include "EventListener.h"
#include "ObstacleEvent.h"

class ObstacleEventListener: public EventListener
{
    public:
        /**
         * Constructor.
         */
        ObstacleEventListener();

        /**
         * Destructor.
         */
        ~ObstacleEventListener();

        /**
         * Called on obstacle detection.
         * @param event Event containing more information.
         */
        virtual void obstacleDetected(const ObstacleEvent &event) = 0;

        /**
         * Called when no obstacle is detected.
         */
        virtual void noObstacle() = 0;
};

#endif
