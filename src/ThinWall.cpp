#include "ThinWall.h"

ThinWall::ThinWall(int x, int y): Obstacle(x, y)
{
    shot = false;
}

ThinWall::~ThinWall()
{
}

bool ThinWall::isAccessible() const
{
    return !shot;
}

bool ThinWall::isShootable() const
{
    return true;
}

bool ThinWall::isJumpable() const
{
    return false;
}
