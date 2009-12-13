/**
 * Pieter De Baets
 * Jasper Van der Jeugt
 * Groep 31
 * TObstacleFactory.cpp
 */
#include "TObstacleFactory.h"

template<class T>
TObstacleFactory<T>::TObstacleFactory()
{
}

template<class T>
TObstacleFactory<T>::~TObstacleFactory()
{
}

template<class T>
Obstacle *TObstacleFactory<T>::createObstacle(int x, int y) const
{
    return new T(x, y);
}
