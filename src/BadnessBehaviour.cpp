#include <iostream>

#include "BadnessBehaviour.h"
#include "Robot.h"
#include "GUI.h"
#include "Obstacle.h"

/* Over 9000 */
#define BADNESS_VERY_BAD 9001
#define BADNESS_MAYBE_BAD 100
#define BADNESS_INCREMENT 2

using namespace std;

BadnessBehaviour::BadnessBehaviour(Robot *robot) : Behaviour()
{
    this->robot = robot;
    lastSeenObstacle = NULL;
    lastDestination = NULL;
    active = false;
}

BadnessBehaviour::~BadnessBehaviour()
{
    if(lastSeenObstacle) delete lastSeenObstacle;
    if(lastDestination) delete lastDestination;
}

bool BadnessBehaviour::isActive()
{
    return active;
}

void BadnessBehaviour::obstacleDetected(const ObstacleEvent &event)
{
    Cell obstacle = *((Cell*) event.getObstacle());

    /* We meet a non-accessible object. */
    if(!event.getObstacle()->isAccessible()) {

        /* If we were standing before this object the last turn, we can't pass
         * there, so we mark it as very bad. */
        if(lastSeenObstacle && *lastSeenObstacle == obstacle)
            badness.insert(obstacle, getBadness(obstacle) + BADNESS_VERY_BAD);

        /* Update the last seen obstacle. */
        if(lastSeenObstacle) delete lastSeenObstacle;
        lastSeenObstacle = new Cell(obstacle.getX(), obstacle.getY());

        /* We meet a moderately bad obstacle when we cannot jump over it or
         * shoot it. */
        if(!event.getObstacle()->isJumpable() && 
            !event.getObstacle()->isShootable()) {
            badness.insert(obstacle, getBadness(obstacle) + BADNESS_MAYBE_BAD);
        }
    /* We met an obstacle we can pass. We store this as 'no obstacle'. */
    } else {
        if(lastSeenObstacle) delete lastSeenObstacle;
        lastSeenObstacle = NULL;
    }

    active = store();
}

void BadnessBehaviour::noObstacle()
{
    if(lastSeenObstacle) delete lastSeenObstacle;
    lastSeenObstacle = NULL;

    active = store();
}

void BadnessBehaviour::action()
{
    Orientation orientation = robot->getOrientation();

    /* Turn as determined by delta */
    while(delta > 0) {
        GUI::show(GUI::ROTATE);
        orientation = increment(orientation);
        delta--;
    }

    robot->setOrientation(orientation);
}

bool BadnessBehaviour::store()
{
    Cell cell = *robot->getCurrentPosition();
    badness.insert(cell, getBadness(cell) + BADNESS_INCREMENT);

    /* Revoke debt (should be dependent on success somehow?) */
    if(lastDestination)
    {
        badness.insert(*lastDestination, getBadness(*lastDestination) - 
            BADNESS_MAYBE_BAD + BADNESS_INCREMENT);
        delete lastDestination;
    }

    /* Find the next best orientation. */
    Orientation orientation = robot->getOrientation();
    int best = getBadness(getNeighbour(cell, orientation));
 
    for(Orientation o = increment(orientation); o != orientation;
            o = increment(o)) {
        int b = getBadness(getNeighbour(cell, o));
        if(b + BADNESS_INCREMENT < best) {
            best = b;
            orientation = o;
        }
    }

    /* Calculate how many times we have to turn to obtain the next best
     * orientation. */
    delta = orientation - robot->getOrientation();
    if(delta < ORIENTATION_START) delta += ORIENTATION_SIZE;

    Cell destination = getNeighbour(cell, orientation);

    /* Add a certain dept to the direction we're taking */
    badness.insert(destination, getBadness(destination) + BADNESS_MAYBE_BAD);
        
    /* Update the last chosen cell. */
    lastDestination = new Cell(destination.getX(), destination.getY());

    return (delta != 0);
}

int BadnessBehaviour::getBadness(const Cell &cell)
{
    int *b = badness.find(cell);
    return b ? *b : 0;
}

const Orientation BadnessBehaviour::increment(const Orientation &orientation)
        const
{
    return (Orientation) ((orientation + 1) % ORIENTATION_SIZE);
}

const Cell BadnessBehaviour::getNeighbour(const Cell &cell,
        const Orientation &orientation) const
{
    switch(orientation) {
        case NORTH: return Cell(cell.getX(), cell.getY() - 1);
        case EAST:  return Cell(cell.getX() + 1, cell.getY());
        case SOUTH: return Cell(cell.getX(), cell.getY() + 1);
        case WEST:  return Cell(cell.getX() - 1, cell.getY());
    }
}
