/**
 * Pieter De Baets
 * Jasper Van der Jeugt
 * Groep 31
 * ThinWall.h
 */
#ifndef THINWALL_H
#define THINWALL_H

#include "Obstacle.h"

/** A thin wall. */
class ThinWall: public Obstacle
{
    public:
        /** 
         * Constructor.
         */
        ThinWall(int x, int y);
        
        /**
         * Destructor.
         */
        virtual ~ThinWall();
        
        /* Implementation. */
        virtual bool isJumpable() const;
        
        /* Implementation. */
        virtual bool isShootable() const;
};

#endif
