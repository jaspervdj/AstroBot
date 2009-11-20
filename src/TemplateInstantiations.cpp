#include "BinarySearchTree.cpp"
#include <string>
class ObstacleFactory;

template class BinarySearchTree<int, int>;
template class BinarySearchTree<std::string, ObstacleFactory*>;

#include "TObstacleFactory.cpp"

template class TObstacleFactory<ThickWall>;
template class TObstacleFactory<ThinWall>;
template class TObstacleFactory<Trench>;
