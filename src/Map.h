#ifndef MAP_H
#define MAP_H

#include <string>

class Cell;
class Robot;

/** Representation of the map/environment */
class Map
{
    public:
        /**
         * Constructor
         */
        Map(const std::string &fileName);
        
        /** 
         * Destructor
         */
        ~Map();
        
        /**
         * Assign robot instance
         */
        void setRobot(Robot *r);
    
    private:
        /** Map dimension **/
        int width;
        int height;
    
        /** Bot startposition */
        Cell *origin;
    
        /** Bot endposition */
        Cell *destination;
        
        /** Robot */
        Robot *robot;
    
};

#endif