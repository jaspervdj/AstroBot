#include "JumpBehaviour.h"
#include "Map.h"
#include "Obstacle.h"

JumpBehaviour::JumpBehaviour(Map *map) : Behaviour()
{
    this->map = map;
    lastJumpableObstacle = NULL;
    active = false;
}

JumpBehaviour::~JumpBehaviour()
{
}

bool JumpBehaviour::isActive()
{
    return active;
}

void JumpBehaviour::obstacleDetected(const ObstacleEvent &event)
{
    Obstacle *obstacle = event.getObstacle();

    /* We just tried jumping over this obstacle, and it failed. It would be
     * supid to fail again. */
    if(lastJumpableObstacle && *lastJumpableObstacle == *obstacle) {
        active = false;
    } else {
        if(obstacle->isJumpable()) {
            lastJumpableObstacle = obstacle;
            active = true;
        } else {
            lastJumpableObstacle = NULL;
            active = false;
        }
    }
}

void JumpBehaviour::noObstacle()
{
    lastJumpableObstacle = NULL;
    active = false;
}

void JumpBehaviour::action()
{
    map->jump();
}