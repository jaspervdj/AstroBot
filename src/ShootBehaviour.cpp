#include "ShootBehaviour.h"
#include "Map.h"
#include "Robot.h"
#include "Obstacle.h"
#include "GUI.h"

ShootBehaviour::ShootBehaviour()
{
    lastShootableObstacle = NULL;
}

ShootBehaviour::~ShootBehaviour()
{
}

void ShootBehaviour::obstacleDetected(const ObstacleEvent &event)
{
    Obstacle *obstacle = event.getObstacle();
    if(obstacle->isShootable() && !obstacle->isAccessible())
        lastShootableObstacle = obstacle;
    else
        lastShootableObstacle = NULL;
    setActive(lastShootableObstacle != NULL);
}

void ShootBehaviour::noObstacle()
{
    lastShootableObstacle = NULL;
    setActive(false);
}

void ShootBehaviour::action()
{
    if(lastShootableObstacle) lastShootableObstacle->shootDown();
    GUI::show(GUI::SHOOT);
}
