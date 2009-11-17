#include "Map.h"
#include "Cell.h"
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