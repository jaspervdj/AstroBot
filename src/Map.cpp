#include <iostream>
#include <cstdlib>
#include <fstream>
#include <exception>

#include "Map.h"
#include "Cell.h"
#include "Obstacle.h"
#include "ObstacleEventListener.h"
#include "TObstacleFactory.h"
#include "Robot.h"

using namespace std;

Map::Map(const string &fileName)
{
    /* Initialize as NULL. */
    origin = destination = NULL;

    /* Open the file. */
    ifstream file(fileName.c_str(), ios_base::in);

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
            cout << "Origin (" << x << ", " << y << ");" << endl;
        /* Set destination. */
        } else if(command == "destination") {
            file >> x >> y;
            destination = new Cell(x, y);
            cout << "Destination (" << x << ", " << y << ");" << endl;
        /* Set dimensions. */
        } else if(command == "dimension") {
            file >> width >> height;
            cout << "Dimension (" << width << ", " << height << ");" << endl;
        /* Obstacle. */
        } else if(command == "obstacle") {
            /* Check the type of the obstacle. */
            string type;
            file >> type;
            ObstacleFactory **factory = factories->get(type);
            /* Factroy found, let it create an object. */
            if(factory) {
                int x, y;
                file >> x >> y;
                Obstacle *obstacle = (*factory)->createObstacle(x, y);
                cout << "Created obstacle of type \"" << type << "\" at (" <<
                        x << ", " << y << ");" << endl;
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

void Map::setRobot(Robot *r)
{
    robot = r;
}

void Map::registerListener(EventListener *listener)
{
    listeners.push_back(listener);
}

void Map::refresh()
{
    for(list<EventListener*>::iterator i = listeners.begin();
            i != listeners.end(); i++) {
        EventListener *listener = *i;
    }
}

int Map::getKey(Cell *cell) const
{
    return cell->getY() * width + cell->getX();
}

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
