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
        TurnBehaviour(Robot *robot);

        /**
         * Destructor.
         */
        virtual ~TurnBehaviour();

        /* Implementation. */
        bool isActive();

        /* Implementation. */
        void obstacleDetected(const ObstacleEvent &event);

        /* Implementation. */
        void noObstacle();

        /* Implementation. */
        void action();

    private:
        /** Robot to control. */
        Robot *robot;
    
        /** Flag to see if this behaviour is active. */
        bool active;
};

#endif
