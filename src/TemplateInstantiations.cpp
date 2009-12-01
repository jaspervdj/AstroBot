#include "BinarySearchTree.cpp"
#include <string>
#include <set>
#include "Cell.h"
#include "Orientation.h"
class ObstacleFactory;
class Obstacle;

template class BinarySearchTree<std::string, ObstacleFactory*>;
template class BinarySearchTree<int, Obstacle*>;
template class BinarySearchTree<Cell, int>;

#include "TObstacleFactory.cpp"

template class TObstacleFactory<ThickWall>;
template class TObstacleFactory<ThinWall>;
template class TObstacleFactory<Trench>;
