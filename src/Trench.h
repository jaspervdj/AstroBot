#ifndef TRENCH_H
#define TRENCH_H

#include "Obstacle.h"

/** A cell in the map */
class Trench : public Obstacle
{
    public:
        /** 
         * Constructor.
         */
        Trench(int x, int y);
        
        /**
         * Destructor.
         */
        virtual ~Trench();
        
        virtual bool isJumpable() const;
        
        virtual bool isShootable() const;
};

#endif
