#include "MoveBehaviour.h"
#include "Map.h"
#include "Robot.h"
#include "Obstacle.h"

MoveBehaviour::MoveBehaviour()
{
}

MoveBehaviour::~MoveBehaviour()
{
}

void MoveBehaviour::obstacleDetected(const ObstacleEvent &event)
{
    setActive(event.getObstacle()->isAccessible());
}

void MoveBehaviour::noObstacle()
{
    setActive(true);
}

void MoveBehaviour::action()
{
    getMap()->move();
}
