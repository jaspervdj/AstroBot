/**
 * Pieter De Baets
 * Jasper Van der Jeugt
 * Groep 31
 * Trench.cpp
 */
#include "Trench.h"

Trench::Trench(int x, int y) : Obstacle(x, y)
{
}

Trench::~Trench()
{
}

bool Trench::isShootable() const
{
    return false;
}

bool Trench::isJumpable() const
{
    return true;
}
