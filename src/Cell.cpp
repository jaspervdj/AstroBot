#include "Cell.h"

Cell::Cell(int x, int y)
{
    this->x = x;
    this->y = y;
}

Cell::~Cell()
{
}

int Cell::getX() const
{
    return x;
}

int Cell::getY() const
{
    return y;
}

bool Cell::operator==(const Cell &other) const
{
    return x == other.x && y == other.y;
}

bool Cell::operator<(const Cell &other) const
{
    if(y < other.y) return true;
    else return x < other.x;
}

bool Cell::operator>(const Cell &other) const
{
    if(y > other.y) return true;
    else return x > other.x;
}
