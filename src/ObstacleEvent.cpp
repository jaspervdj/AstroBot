#include "ObstacleEvent.h"

ObstacleEvent::ObstacleEvent(Obstacle* obstacle)
{
    this->obstacle = obstacle;
}

ObstacleEvent::~ObstacleEvent()
{
}

Obstacle *ObstacleEvent::getObstacle()
{
    return obstacle;
}