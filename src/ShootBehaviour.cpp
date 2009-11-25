#include "ShootBehaviour.h"
#include "Robot.h"
#include "Obstacle.h"
#include "GUI.h"

#include <iostream>

using namespace std;

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
    cout << "ShootBehaviour: obstacle detected!" << endl;
    setActive(lastShootableObstacle != NULL);
}

void ShootBehaviour::noObstacle()
{
    lastShootableObstacle = NULL;
    cout << "ShootBehaviour: no obstacle detected!" << endl;
    setActive(false);
}

bool ShootBehaviour::isActive()
{
    cout << "ShootBehaviour: active? " << Behaviour::isActive() << endl;
    return Behaviour::isActive();
}

void ShootBehaviour::action()
{
    if(lastShootableObstacle) lastShootableObstacle->shoot();
    GUI::show(GUI::SHOOT);
    cout << "Woot, shooting" << endl;
}
