#include "JumpBehaviour.h"
#include "Map.h"
#include "Robot.h"
#include "Obstacle.h"

JumpBehaviour::JumpBehaviour()
{
    lastJumpableObstacle = NULL;
}

JumpBehaviour::~JumpBehaviour()
{
}

void JumpBehaviour::obstacleDetected(const ObstacleEvent &event)
{
    Obstacle *obstacle = event.getObstacle();

    /* We just tried jumping over this obstacle, and it failed. It would be
     * supid to fail again. */
    if(lastJumpableObstacle && *lastJumpableObstacle == *obstacle) {
        setActive(false);
    } else {
        if(obstacle->isJumpable()) {
            lastJumpableObstacle = obstacle;
            setActive(true);
        } else {
            lastJumpableObstacle = NULL;
            setActive(false);
        }
    }
}

void JumpBehaviour::noObstacle()
{
    lastJumpableObstacle = NULL;
    setActive(false);
}

void JumpBehaviour::action()
{
    getMap()->jump();
}
