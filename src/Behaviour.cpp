#include "Behaviour.h"
#include "Map.h"

Behaviour::Behaviour()
{
    map = NULL;
    active = false;
}

Behaviour::~Behaviour()
{
}

bool Behaviour::isActive()
{
    return active;
}

void Behaviour::setActive(bool active)
{
    this->active = active;
}

Map *Behaviour::getMap() const
{
    return map;
}

void Behaviour::setMap(Map *robot)
{
    this->map = map;
}
