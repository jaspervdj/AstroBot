#ifndef MAP_H
#define MAP_H

#include <list>
#include <string>

class Cell;
class EventListener;

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
         * Add an eventlistener.
         * @param listener EventListener to add.
         */
        void registerListener(EventListener *listener);

        /**
         * Notify EventListeners of pending events.
         */
        void refresh();
    
    private:
        /** Map dimensions **/
        int width, height;
    
        /** Bot startposition */
        Cell* origin;
    
        /** Bot endposition */
        Cell* destination;
    
        /** EventListeners */
        std::list<EventListener*> listeners;
};

#endif
