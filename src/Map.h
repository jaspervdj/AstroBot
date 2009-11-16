#ifndef MAP_H
#define MAP_H

class Cell;

/** Representation of the map/environment */
class Map
{
    public:
        /** constructor */
        Map(const std::string &fileName);
        
        /** destructor */
        ~Map();
        
        
    
    private:
        /** Map dimension **/
        int width;
        int height;
    
        /** Bot startposition */
        Cell* origin;
    
        /** Bot endposition */
        Cell* destination;
    
};

#endif