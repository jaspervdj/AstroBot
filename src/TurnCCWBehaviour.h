#ifndef TURNCCWBEHAVIOUR_H
#define TURNCCWBEHAVIOUR_H

#include "Behaviour.h"
#include "ObstacleEventListener.h"
#include "Orientation.h"

/**
 * Behaviour that reacts when the destination is reached.
 */
class TurnCCWBehaviour: public Behaviour,
        public ObstacleEventListener
{
    public:
        /**
         * Constructor.
         */
        TurnCCWBehaviour();

        /**
         * Destructor.
         */
        virtual ~TurnCCWBehaviour();

        /* Implementation. */
        void action();

        /* Implementation. */
        void obstacleDetected(const ObstacleEvent &event);

        /* Implementation. */
        void noObstacle();

    private:
        /**
         * Calculate the next orientation CCW from the current
         */
        Orientation getNextOrientation(Orientation current);
};

#endif
