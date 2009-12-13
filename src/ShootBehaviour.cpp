/**
 * Pieter De Baets
 * Jasper Van der Jeugt
 * Groep 31
 * ShootBehaviour.cpp
 */
#include "ShootBehaviour.h"
#include "Obstacle.h"
#include "GUI.h"

ShootBehaviour::ShootBehaviour() : Behaviour()
{
    lastShootableObstacle = NULL;
    active = false;
}

ShootBehaviour::~ShootBehaviour()
{
}

bool ShootBehaviour::isActive()
{
    return active;
}

void ShootBehaviour::obstacleDetected(const ObstacleEvent &event)
{
    Obstacle *obstacle = event.getObstacle();
    if(obstacle->isShootable() && !obstacle->isAccessible())
        lastShootableObstacle = obstacle;
    else
        lastShootableObstacle = NULL;
    active = (lastShootableObstacle != NULL);
}

void ShootBehaviour::noObstacle()
{
    lastShootableObstacle = NULL;
    active = false;
}

void ShootBehaviour::action()
{
    if(lastShootableObstacle) lastShootableObstacle->shootDown();
    GUI::show(GUI::SHOOT);
}
