#include <iostream>
#include <cstdlib>
#include <fstream>

#include "Map.h"
#include "Cell.h"
#include "Obstacle.h"
#include "Trench.h"
#include "ObstacleEventListener.h"
#include "Robot.h"

using namespace std;

Map::Map(const string &fileName)
{
    Trench t(1, 2);
    
    cout << t.getX() << "-" << t.getY() << endl;
    
    // how I read file?
    // files goes into program
    // how is babby formed
    
    ifstream file(fileName.c_str(), ios_base::in);
    
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
