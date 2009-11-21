#ifndef MAP_H
#define MAP_H

#include "BinarySearchTree.h"
#include <list>
#include <string>

class Cell;
class EventListener;
class Robot;
class ObstacleFactory;
class Obstacle;

/** Representation of the map/environment */
class Map
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
         */
        void setRobot(Robot *r);

        /**
         * Add an eventlistener.
         * @param listener EventListener to add.
         */
        void registerListener(EventListener *listener);

        /**
         * Notify EventListeners of pending events.
         */
        void refresh();

    protected:
        /**
         * Get the key for a certain cell.
         * @param The key for a certain cell.
         */
        int getKey(Cell *cell) const;
    
    private:
        /** Map dimensions **/
        int width, height;
    
        /** Bot startposition */
        Cell *origin;
    
        /** Bot endposition */
        Cell *destination;
        
        /** Robot */
        Robot *robot;
    
        /** EventListeners */
        std::list<EventListener*> listeners;

        /** Obstacles in the map. */
        BinarySearchTree<int, Obstacle*> obstacles;

        /** Factories to create objects. */
        static BinarySearchTree<std::string, ObstacleFactory*> *factories;
};

#endif
