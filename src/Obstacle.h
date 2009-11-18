#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Cell.h"

/** A cell in the map */
class Obstacle : public Cell
{
    public:
        /** 
         * Constructor.
         */
        Obstacle(int x, int y);
        
        /**
         * Destructor.
         */
        virtual ~Obstacle();
        
        /**
         * Jumpable?
         * @return ok
         */
        virtual bool isJumpable() const = 0;
        
        /**
         * Shootable?
         * @return ok
         */
         virtual bool isShootable() const = 0;
};

#endif
