#ifndef MOVEBEHAVIOUR_H
#define MOVEBEHAVIOUR_H

#include "Behaviour.h"
#include "ObstacleEventListener.h"

/**
 * Behaviour that reacts when the robot can move.
 */
class MoveBehaviour: public Behaviour,
        public ObstacleEventListener
{
    public:
        /**
         * Constructor.
         */
        MoveBehaviour(Map *map, Robot *robot);

        /**
         * Destructor.
         */
        virtual ~MoveBehaviour();

        /* Implementation. */
        void action();

        /* Implementation. */
        void obstacleDetected(const ObstacleEvent &event);

        /* Implementation. */
        void noObstacle();
};

#endif
