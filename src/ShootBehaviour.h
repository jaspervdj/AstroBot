#ifndef SHOOTBEHAVIOUR_H
#define SHOOTBEHAVIOUR_H

#include "Behaviour.h"
#include "ObstacleEventListener.h"

/**
 * Behaviour that reacts when we can shoot an obstacle.
 */
class ShootBehaviour: public Behaviour,
        public ObstacleEventListener
{
    public:
        /**
         * Constructor.
         */
        ShootBehaviour(Map *map, Robot *robot);

        /**
         * Destructor.
         */
        virtual ~ShootBehaviour();
        
        /* Implementation. */
        void action();

        /* Implementation. */
        void obstacleDetected(const ObstacleEvent &event);

        /* Implementation. */
        void noObstacle();

    private:
        /** Last detected shootable obstacle. NULL if no obstacle detected
         *  during last scan. */
        Obstacle *lastShootableObstacle;
};

#endif
