#include "BinarySearchTree.cpp"
#include <string>
class ObstacleFactory;
class Obstacle;

template class BinarySearchTree<std::string, ObstacleFactory*>;
template class BinarySearchTree<int, Obstacle*>;

#include "TObstacleFactory.cpp"

template class TObstacleFactory<ThickWall>;
template class TObstacleFactory<ThinWall>;
template class TObstacleFactory<Trench>;
