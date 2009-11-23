#include "Behaviour.h"
#include "Map.h"

Behaviour::Behaviour()
{
    map = NULL;
}

Behaviour::~Behaviour()
{
}

Map *Behaviour::getMap() const
{
    return map;
}

void Behaviour::setMap(Map *robot)
{
    this->map = map;
}
