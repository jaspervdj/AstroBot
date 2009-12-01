#ifndef TURNBEHAVIOUR_H
#define TURNBEHAVIOUR_H

#include "Behaviour.h"
#include "ObstacleEventListener.h"

/**
 * Behaviour that reacts when the destination is reached.
 */
class TurnBehaviour: public Behaviour, public ObstacleEventListener
{
    public:
        /**
         * Constructor.
         */
        TurnBehaviour(Map *map, Robot *robot);

        /**
         * Destructor.
         */
        virtual ~TurnBehaviour();

        /* Implementation. */
        void obstacleDetected(const ObstacleEvent &event);

        /* Implementation. */
        void noObstacle();

        /* Implementation. */
        void action();
};

#endif
