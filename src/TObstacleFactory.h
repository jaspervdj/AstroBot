#ifndef TOBSTACLEFACTORY_H
#define TOBSTACLEFACTORY_H

#include "ObstacleFactory.h"

template <class T>
class TObstacleFactory: public ObstacleFactory
{
    public:
        /**
         * Constructor.
         */
        TObstacleFactory();

        /**
         * Destructor.
         */
        ~TObstacleFactory();

        /* Implementation. */
        Obstacle *createObstacle(int x, int y) const;
};

#endif
