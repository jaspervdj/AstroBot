#include "Map.h"
#include "Cell.h"
#include "ObstacleEventListener.h"
#include "Robot.h"

using namespace std;

Map::Map(const string &fileName)
{
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
