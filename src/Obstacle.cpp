#include "Obstacle.h"

Obstacle::Obstacle(int x, int y) : Cell(x, y)
{
    accessible = false;
}

Obstacle::~Obstacle()
{
}

void Obstacle::shoot()
{
    accessible = !isShootable();
}
