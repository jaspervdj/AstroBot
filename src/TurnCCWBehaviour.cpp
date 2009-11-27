#include "TurnCCWBehaviour.h"
#include "Map.h"
#include "Robot.h"
#include "ObstacleEvent.h"
#include "Obstacle.h"
#include "Orientation.h"
#include "GUI.h"

TurnCCWBehaviour::TurnCCWBehaviour()
{
}

TurnCCWBehaviour::~TurnCCWBehaviour()
{
}

void TurnCCWBehaviour::obstacleDetected(const ObstacleEvent &event)
{
    Robot *robot = getMap()->getRobot();
    
    /* consider only of it there's something 
    accessible/jumpable/shootable to the left */
    Orientation oldOrientation = robot->getOrientation();
    robot->setOrientation(getNextOrientation(oldOrientation));
    
    Cell left = getMap()->getNextCell(robot->getCurrentPosition());
    if(getMap()->isInRange(&left)) {
        Obstacle* obstacle = getMap()->getObstacleAt(&left);
        if(obstacle == NULL || obstacle->isAccessible() || 
           obstacle->isJumpable() || obstacle->isShootable())
        {
            setActive(true);
        }
    }
    
    /* restore old orientation */
    robot->setOrientation(oldOrientation);
}

void TurnCCWBehaviour::noObstacle()
{
    setActive(false);
}

void TurnCCWBehaviour::action()
{
    Orientation current = getMap()->getRobot()->getOrientation();

    Orientation next = getNextOrientation(current);

    getMap()->getRobot()->setOrientation(next);
    
    GUI::show(GUI::ROTATE);
    GUI::show(GUI::ROTATE);
    GUI::show(GUI::ROTATE);
}

Orientation TurnCCWBehaviour::getNextOrientation(Orientation current)
{
    Orientation next;
    if(current == SOUTH) next = EAST;
    else if(current == WEST) next = SOUTH;
    else if(current == NORTH) next = WEST;
    else if(current == EAST) next = NORTH;
    return next;
}
