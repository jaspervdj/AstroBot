#ifndef JUMPBEHAVIOUR_H
#define JUMPBEHAVIOUR_H

#include "Behaviour.h"
#include "ObstacleEventListener.h"

/**
 * Behaviour that reacts when the robot can jump.
 */
class JumpBehaviour: public Behaviour,
        public ObstacleEventListener
{
    public:
        /**
         * Constructor.
         */
        JumpBehaviour();

        /**
         * Destructor.
         */
        virtual ~JumpBehaviour();

        /* Implementation. */
        void action();

        /* Implementation. */
        void obstacleDetected(const ObstacleEvent &event);

        /* Implementation. */
        void noObstacle();
};

#endif
