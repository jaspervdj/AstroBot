/**
 * Pieter De Baets
 * Jasper Van der Jeugt
 * Groep 31
 * ObstacleEvent.cpp
 */
#include "ObstacleEvent.h"

ObstacleEvent::ObstacleEvent(Obstacle* obstacle)
{
    this->obstacle = obstacle;
}

ObstacleEvent::~ObstacleEvent()
{
}

Obstacle *ObstacleEvent::getObstacle() const
{
    return obstacle;
}
