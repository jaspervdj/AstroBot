#include "JumpBehaviour.h"
#include "Map.h"
#include "Robot.h"
#include "Obstacle.h"

JumpBehaviour::JumpBehaviour()
{
}

JumpBehaviour::~JumpBehaviour()
{
}

void JumpBehaviour::obstacleDetected(const ObstacleEvent &event)
{
    setActive(event.getObstacle()->isJumpable());
}

void JumpBehaviour::noObstacle()
{
    setActive(false);
}

void JumpBehaviour::action()
{
    getMap()->jump();
}
