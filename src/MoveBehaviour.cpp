#include "MoveBehaviour.h"
#include "Map.h"
#include "Robot.h"
#include "Obstacle.h"

MoveBehaviour::MoveBehaviour(Map *map, Robot *robot)
        : Behaviour(map, robot)
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
    map->move();
}
