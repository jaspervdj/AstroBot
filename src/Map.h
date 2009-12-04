#ifndef MAP_H
#define MAP_H

#include "BinarySearchTree.h"
#include "EventProducer.h"
#include <string>

class Cell;
class EventListener;
class Robot;
class ObstacleFactory;
class Obstacle;

/** Representation of the map/environment */
class Map: public EventProducer
{
    public:    
        /**
         * Constructor.
         * @param fileName File to load the map from.
         */
        Map(const std::string &fileName);
        
        /**
         * Destructor.
         */
        ~Map();

        /**
         * Assign robot instance
         * @param robot Robot to set.
         */
        void setRobot(Robot *robot);

        /**
         * Notify EventListeners of pending events.
         */
        void refresh();
        
        /**
         * Move the robot forward
         */
        void move();

        /**
         * Makes the robot jump (over an obstacle)
         */
        void jump();

    protected:
        /**
         * Get the key for a certain cell.
         * @param The key for a certain cell.
         */
        int getKey(Cell *cell) const;
    
        /**
         * Get next position
         * @param current  Current cell
         */
        Cell getNextCell(Cell *current) const;

        /**
         * Check if a cell falls within the map range.
         * @param cell Cell to check.
         * @return If the cell falls within the map range.
         */
        bool isInRange(Cell *cell) const;

    private: 
        /** Map file base dir */
        static const std::string MAP_DIR;
        
        /** Map dimensions **/
        int width, height;
    
        /** Bot startposition */
        Cell *origin;
    
        /** Bot endposition */
        Cell *destination;
        
        /** Robot */
        Robot *robot;

        /** Obstacles in the map. */
        BinarySearchTree<int, Obstacle*> obstacles;

        /** Factories to create objects. */
        static BinarySearchTree<std::string, ObstacleFactory*> *factories;
};

#endif
