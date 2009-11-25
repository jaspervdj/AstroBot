#ifndef THICKWALL_H
#define THICKWALL_H

#include "Obstacle.h"

/** A thick wall. */
class ThickWall: public Obstacle
{
    public:
        /** 
         * Constructor.
         */
        ThickWall(int x, int y);
        
        /**
         * Destructor.
         */
        virtual ~ThickWall();
        
        /* Implementation. */
        virtual bool isJumpable() const;
        
        /* Implementation. */
        virtual bool isShootable() const;
};

#endif
