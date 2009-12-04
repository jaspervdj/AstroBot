#include "BadnessBehaviour.h"
#include "Robot.h"
#include "GUI.h"
#include "Obstacle.h"
#include <iostream>
#include <iomanip>

using namespace std;

BadnessBehaviour::BadnessBehaviour(Map *map, Robot *robot)
        : Behaviour(map, robot)
{
    lastSeenObstacle = NULL;
}

BadnessBehaviour::~BadnessBehaviour()
{
    if(lastSeenObstacle) delete lastSeenObstacle;
}

void BadnessBehaviour::obstacleDetected(const ObstacleEvent &event)
{
    /* We meet a non-accessible object. */
    if(!event.getObstacle()->isAccessible()) {

        Cell obstacle = *((Cell*) event.getObstacle());

        /* If we were standing before this object the last turn, we can't pass
         * there, so we mark it as very bad. */
        if(lastSeenObstacle && *lastSeenObstacle == obstacle)
            badness.put(obstacle, getBadness(obstacle) + 9001);

        /* Update the last seen obstacle. */
        if(lastSeenObstacle) delete lastSeenObstacle;
        lastSeenObstacle = new Cell(obstacle.getX(), obstacle.getY());

        /* We meet a moderately bad obstacle when we cannot jump over it or
         * shoot it. */
        if(!event.getObstacle()->isJumpable() &&
                !event.getObstacle()->isShootable()) {
            badness.put(obstacle, getBadness(obstacle) + 100);
        }
    /* We met an obstacle we can pass. We store this as 'no obstacle'. */
    } else {
        if(lastSeenObstacle) delete lastSeenObstacle;
        lastSeenObstacle = NULL;
    }

    setActive(store());
}

void BadnessBehaviour::noObstacle()
{
    if(lastSeenObstacle) delete lastSeenObstacle;
    lastSeenObstacle = NULL;
    setActive(store());
}

void BadnessBehaviour::action()
{
    Orientation orientation = robot->getOrientation();
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
    badness.put(cell, getBadness(cell) + 2);

    /* Find the next best orientation. */
    Orientation orientation = robot->getOrientation();
    int best = getBadness(getNeighbour(cell, orientation));
    for(Orientation o = increment(orientation); o != orientation;
            o = increment(o)) {
        int b = getBadness(getNeighbour(cell, o));
        if(b < best) {
            best = b;
            orientation = o;
        }
    }

    /* Calculate how many times we have to turn to obtain the next best
     * orientation. */
    delta = orientation - robot->getOrientation();
    if(delta < ORIENTATION_START) delta += ORIENTATION_SIZE;
    Cell destination = getNeighbour(cell, orientation);

    return (delta != 0);
}

int BadnessBehaviour::getBadness(const Cell &cell)
{
    return badness.contains(cell) ? badness.get(cell) : 0;
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
