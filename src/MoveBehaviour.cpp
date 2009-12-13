/**
 * Pieter De Baets
 * Jasper Van der Jeugt
 * Groep 31
 * MoveBehaviour.cpp
 */
#include "MoveBehaviour.h"
#include "Map.h"
#include "Robot.h"
#include "Obstacle.h"

MoveBehaviour::MoveBehaviour(Map *map) : Behaviour()
{
    this->map = map;
    active = false;
}

MoveBehaviour::~MoveBehaviour()
{
}

bool MoveBehaviour::isActive()
{
    return active;
}

void MoveBehaviour::obstacleDetected(const ObstacleEvent &event)
{
    active = event.getObstacle()->isAccessible();
}

void MoveBehaviour::noObstacle()
{
    active = true;
}

void MoveBehaviour::action()
{
    map->move();
}
