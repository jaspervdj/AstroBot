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
        JumpBehaviour(Map *map, Robot *robot);

        /**
         * Destructor.
         */
        virtual ~JumpBehaviour();

        /* Implementation. */
        void obstacleDetected(const ObstacleEvent &event);

        /* Implementation. */
        void noObstacle();

        /* Implementation. */
        void action();

    private:
        /** Limited memory. */
        Obstacle *lastJumpableObstacle;
};

#endif
