#include "Behaviour.h"
#include "Map.h"

Behaviour::Behaviour(Map *map, Robot *robot)
{
    this->map = map;
    this->robot = robot;
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
