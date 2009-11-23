#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <exception>

#include "Map.h"
#include "Cell.h"
#include "Obstacle.h"
#include "ObstacleEventListener.h"
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
            ObstacleFactory **factory = factories->get(type);
            /* Factory found, let it create an object. */
            if(factory) {
                int x, y;
                file >> x >> y;
                Obstacle *obstacle = (*factory)->createObstacle(x, y);
                obstacles.put(getKey(obstacle), obstacle);
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

Robot *Map::getRobot() const
{
    return robot;
}

void Map::setRobot(Robot *robot)
{
    this->robot = robot;
    robot->addNextMove(*origin);
}

void Map::registerListener(EventListener *listener)
{
    listeners.push_back(listener);
}

void Map::refresh()
{
    Cell* current = robot->getCurrentPosition();
    Cell next = getNextCell(current);
    
    Obstacle** obstacle;
    if(*current == next) *obstacle = new ThickWall(next.getX(), next.getY());
    else obstacle = obstacles.get(getKey(&next));
    
    ObstacleEvent obstacleEvent(obstacle ? *obstacle : NULL);
    
    for(list<EventListener*>::iterator i = listeners.begin();
            i != listeners.end(); i++) {
        EventListener *listener = *i;
        
        ObstacleEventListener *obstacleListener = 
            dynamic_cast<ObstacleEventListener*>(listener);
        if(!obstacleListener) continue;
            
        if(!obstacle) obstacleListener->noObstacle();
        else obstacleListener->obstacleDetected(obstacleEvent);
    }
}

int Map::getKey(Cell *cell) const
{
    return cell->getY() * width + cell->getX();
}

Cell Map::getNextCell(Cell *current)
{
    int x = current->getX();
    int y = current->getY();
    
    Orientation orientation = robot->getOrientation();
    if(orientation == NORTH) y -= robot->getSpeed();
    else if(orientation == EAST) x += robot->getSpeed();
    else if(orientation == SOUTH) y += robot->getSpeed();
    else if(orientation == WEST) x -= robot->getSpeed();
    
    if(x < 0 || x >= width) x = current->getX();
    if(y < 0 || y >= height) y = current->getY();
    
    return Cell(x, y);
}

void Map::move()
{
    Cell next = getNextCell(robot->getCurrentPosition());
    if(obstacles.contains(getKey(&next))) return;
    
    GUI::show(GUI::MOVE);
    robot->addNextMove(next);
}

void Map::jump()
{
    Cell next = getNextCell(robot->getCurrentPosition());
    Obstacle **obstacle = obstacles.get(getKey(&next));
    
    // don't jump if there's an obstacle which isn't jumpable
    if(obstacle && !(*obstacle)->isJumpable()) return;
    
    // can only land on a cell where there's no obstacle
    Cell destination = getNextCell(&next);
    if(obstacles.contains(getKey(&destination))) return;
    
    GUI::show(GUI::JUMP);
    robot->addNextMove(destination);
}

const string Map::MAP_DIR = "./maps";

/** Function to create initial obstacle factories. */
BinarySearchTree<string, ObstacleFactory*> *createObstacleFactories()
{
    static BinarySearchTree<string, ObstacleFactory*> factories;

    static ThickWallObstacleFactory thickWallObstacleFactory;
    factories.put("thick_wall", &thickWallObstacleFactory);

    static ThinWallObstacleFactory thinWallObstacleFactory;
    factories.put("thin_wall", &thinWallObstacleFactory);

    static TrenchObstacleFactory trenchObstacleFactory;
    factories.put("trench", &trenchObstacleFactory);

    return &factories;
}

/* Implementation of our static factories. */
BinarySearchTree<string, ObstacleFactory*> *Map::factories =
        createObstacleFactories();
