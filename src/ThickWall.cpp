/**
 * Pieter De Baets
 * Jasper Van der Jeugt
 * Groep 31
 * ThickWall.cpp
 */
#include "ThickWall.h"

ThickWall::ThickWall(int x, int y): Obstacle(x, y)
{
}

ThickWall::~ThickWall()
{
}

bool ThickWall::isShootable() const
{
    return false;
}

bool ThickWall::isJumpable() const
{
    return false;
}
