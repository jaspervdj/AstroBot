#include "SmartTurnBehaviour.h"
#include "Robot.h"
#include "GUI.h"
#include "Obstacle.h"
#include <iostream>
#include <iomanip>

using namespace std;

SmartTurnBehaviour::SmartTurnBehaviour(Map *map, Robot *robot)
        : Behaviour(map, robot)
{
}

SmartTurnBehaviour::~SmartTurnBehaviour()
{
}

void SmartTurnBehaviour::obstacleDetected(const ObstacleEvent &event)
{
    if(!event.getObstacle()->isAccessible() &&
            !event.getObstacle()->isJumpable() &&
            !event.getObstacle()->isShootable()) {
        Cell obstacle = *((Cell*) event.getObstacle());
        badness.put(obstacle, getBadness(obstacle) + 100);
    }

    setActive(store());
}

void SmartTurnBehaviour::noObstacle()
{
    setActive(store());
}

void SmartTurnBehaviour::action()
{
    Orientation orientation = robot->getOrientation();
    while(delta > 0) {
        GUI::show(GUI::ROTATE);
        orientation = increment(orientation);
        delta--;
    }

    robot->setOrientation(orientation);
}

bool SmartTurnBehaviour::store()
{
    Cell cell = *robot->getCurrentPosition();
    badness.put(cell, getBadness(cell) + 2);

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

    delta = orientation - robot->getOrientation();
    if(delta < ORIENTATION_START) delta += ORIENTATION_SIZE;
    Cell destination = getNeighbour(cell, orientation);
    badness.put(destination, getBadness(destination) + 1);

    return (delta != 0);
}

int SmartTurnBehaviour::getBadness(const Cell &cell)
{
    return badness.contains(cell) ? badness.get(cell) : 0;
}

const Orientation SmartTurnBehaviour::increment(const Orientation &orientation)
        const
{
    return (Orientation) ((orientation + 1) % ORIENTATION_SIZE);
}

const Cell SmartTurnBehaviour::getNeighbour(const Cell &cell,
        const Orientation &orientation) const
{
    switch(orientation) {
        case NORTH: return Cell(cell.getX(), cell.getY() - 1);
        case EAST:  return Cell(cell.getX() + 1, cell.getY());
        case SOUTH: return Cell(cell.getX(), cell.getY() + 1);
        case WEST:  return Cell(cell.getX() - 1, cell.getY());
    }
}
