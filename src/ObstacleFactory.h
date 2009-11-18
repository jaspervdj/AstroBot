#ifndef OBSTACLEFACTORY_H
#define OBSTACLEFACTORY_H

class Obstacle;

/**
 * Factory to create different kinds of obstacles.
 */
class ObstacleFactory
{
    public:
        /**
         * Constructor.
         */
        ObstacleFactory();

        /**
         * Destructor.
         */
        virtual ~ObstacleFactory();

        /**
         * Create a new obstacle.
         * @param x X coordinate.
         * @param y Y coordinate.
         * @return A new obstacle.
         */
        virtual Obstacle *createObstacle(int x, int y) const = 0;
};

#endif
