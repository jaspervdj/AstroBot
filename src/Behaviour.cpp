#include "Behaviour.h"
#include "Robot.h"

Behaviour::Behaviour()
{
    robot = NULL;
}

Behaviour::~Behaviour()
{
}

Robot *Behaviour::getRobot() const
{
    return robot;
}

void Behaviour::setRobot(Robot *robot)
{
    this->robot = robot;
}
