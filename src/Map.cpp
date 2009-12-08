#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <exception>

#include "Map.h"
#include "Cell.h"
#include "Obstacle.h"
#include "ObstacleEventListener.h"
#include "DestinationEventListener.h"
#include "TObstacleFactory.h"
#include "Robot.h"
#include "GUI.h"
#include "ThickWall.h"

using namespace std;

Map::Map(const string &fileName)
{
    /* Initialize as NULL. */
    origin = destination = NULL;

    /* Open the file. */
    stringstream path;
    path << MAP_DIR << "/" << fileName;
    ifstream file(path.str().c_str(), ios_base::in);

    /* Read through file. */
    while(file.good()) {
        /* The first token on a line is a command. */
        string command;
        int x, y;
        file >> command;

        /* Set origin. */
        if(command == "origin") {
            file >> x >> y;
            origin = new Cell(x, y);
        /* Set destination. */
        } else if(command == "destination") {
            file >> x >> y;
            destination = new Cell(x, y);
        /* Set dimensions. */
        } else if(command == "dimension") {
            file >> width >> height;
        /* Obstacle. */
        } else if(command == "obstacle") {
            /* Check the type of the obstacle. */
            string type;
            file >> type;
            /* Factory found, let it create an object. */
            ObstacleFactory **factory = factories->find(type);
            if(factory) {
                int x, y;
                file >> x >> y;
                Obstacle *obstacle = (*factory)->createObstacle(x, y);
                obstacles.insert(getKey(obstacle), obstacle);
            /* No such obstacle. */
            } else {
                cerr << "Warning: no obstacle of type \"" <<
                        type << "\"" << endl;
            }
        }
    }
}

Map::~Map()
{
    if(origin) delete origin;
    if(destination) delete destination;

    int arraySize;
    Obstacle **allObstacles = obstacles.getAllValues(arraySize);
    for(int i = 0; i < arraySize; i++) {
        delete allObstacles[i];
    }
    delete[] allObstacles;
}

void Map::setRobot(Robot *robot)
{
    this->robot = robot;
    robot->addNextMove(*origin);
}

void Map::refresh()
{
    Cell* current = robot->getCurrentPosition();
    Cell next = getNextCell(current);
    
    if(*current == *destination) {
        DestinationEvent event(current);
        fireDestinationReached(event);
    }

    int key = getKey(&next);
    Obstacle **obstacle = obstacles.find(key);

    /* Used when we have to create a new obstacle. */
    Obstacle *tmp;
    bool deleteObstacle = false;

    /* Not in range, create a virtual obstacle. */
    if(!obstacle && !isInRange(&next)) {
        tmp = new ThickWall(next.getX(), next.getY());
        obstacle = &tmp;
        deleteObstacle = true;
    }

    /* Found obstacle, we're going to need some events. */
    if(obstacle) {
        ObstacleEvent event(*obstacle);
        fireObstacleDetected(*obstacle);
    /* No obstacle, fire some events as well. */
    } else {
        fireNoObstacle();
    }

    if(deleteObstacle) delete tmp;
}

void Map::move()
{
    Cell last = *robot->getCurrentPosition();
    Cell next = getNextCell(&last);
    
    /* Deny move if there is an obstacle or it moves the robot out of the map.
     */
    for(int i = 0; i < robot->getSpeed(); i++)
    {
        int key = getKey(&next);
        Obstacle **obstacle = obstacles.find(key);
        if(isInRange(&next) && (!obstacle || (*obstacle)->isAccessible())) {
            
            GUI::show(GUI::MOVE);
            
            last = next;
            next = getNextCell(&last);
        }
    }
    
    if(!(last == *robot->getCurrentPosition())) robot->addNextMove(last);
}

void Map::jump()
{
    Cell next = getNextCell(robot->getCurrentPosition());
    
    /* Don't jump if there's an obstacle which isn't jumpable */
    int key = getKey(&next);
    Obstacle **obstacle = obstacles.find(key);
    if(obstacle && !(*obstacle)->isJumpable()) return;
    
    /* Can only land on a cell where there's no obstacle and the cell is
     * within the map. */
    Cell destination = getNextCell(&next);
    int destinationKey = getKey(&destination);
    obstacle = obstacles.find(destinationKey);
    if((obstacle && !(*obstacle)->isAccessible()) || !isInRange(&next)) return;
    
    GUI::show(GUI::JUMP);
    robot->addNextMove(destination);
}

int Map::getKey(Cell *cell) const
{
    return cell->getY() * width + cell->getX();
}

Cell Map::getNextCell(Cell *current) const
{
    int x = current->getX();
    int y = current->getY();
    
    Orientation orientation = robot->getOrientation();
    if(orientation == NORTH) y --;
    else if(orientation == EAST) x++;
    else if(orientation == SOUTH) y ++;
    else if(orientation == WEST) x --;
    
    return Cell(x, y);
}

bool Map::isInRange(Cell *cell) const
{
    return cell->getX() >= 0 && cell->getX() < width &&
            cell->getY() >= 0 && cell->getY() < height;
}

const string Map::MAP_DIR = "./maps";

/** Function to create initial obstacle factories. */
BinarySearchTree<string, ObstacleFactory*> *createObstacleFactories()
{
    static BinarySearchTree<string, ObstacleFactory*> factories;

    static ThickWallObstacleFactory thickWallObstacleFactory;
    factories.insert("thick_wall", &thickWallObstacleFactory);

    static ThinWallObstacleFactory thinWallObstacleFactory;
    factories.insert("thin_wall", &thinWallObstacleFactory);

    static TrenchObstacleFactory trenchObstacleFactory;
    factories.insert("trench", &trenchObstacleFactory);

    return &factories;
}

/* Implementation of our static factories. */
BinarySearchTree<string, ObstacleFactory*> *Map::factories =
        createObstacleFactories();
