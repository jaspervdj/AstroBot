#include <iostream>
#include <cstdlib>
#include <fstream>
#include <exception>

#include "Map.h"
#include "Cell.h"
#include "Obstacle.h"
#include "Trench.h"
#include "ObstacleEventListener.h"
#include "Robot.h"

using namespace std;

Map::Map(const string &fileName)
{
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


        }
    }

    /* Read in file. */

    Trench t(1, 2);
    
    cout << t.getX() << "-" << t.getY() << endl;
    
    // how I read file?
    // files goes into program
    // how is babby formed
    
    char input[255];
    file.getline(input, 255);
    cout << input;// << endl;
    //file.getline(input, 255);
    //cout << input << endl;
}

Map::~Map()
{
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
    }
}
