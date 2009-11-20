#ifndef TOBSTACLEFACTORY_H
#define TOBSTACLEFACTORY_H

#include "ObstacleFactory.h"
#include "ThickWall.h"
#include "ThinWall.h"
#include "Trench.h"

/**
 * We implement the different kinds of obstacle factories
 * through templates, saves us some typing.
 */
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

typedef TObstacleFactory<ThickWall> ThickWallObstacleFactory;
typedef TObstacleFactory<ThinWall> ThinWallObstacleFactory;
typedef TObstacleFactory<Trench> TrenchObstacleFactory;

#endif
