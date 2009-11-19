#include "BinarySearchTree.cpp"
#include <string>
class ObstacleFactory;

template class BinarySearchTree<int, int>;
template class BinarySearchTree<std::string, ObstacleFactory*>;

#include "TObstacleFactory.cpp"
#include "Trench.h"

template class TObstacleFactory<Trench>;
