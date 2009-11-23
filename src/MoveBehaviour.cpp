#include "MoveBehaviour.h"
#include "Map.h"
#include "Robot.h"

MoveBehaviour::MoveBehaviour()
{
}

MoveBehaviour::~MoveBehaviour()
{
}

void MoveBehaviour::obstacleDetected(const ObstacleEvent &event)
{
    setActive(false);
}

void MoveBehaviour::noObstacle()
{
    setActive(true);
}