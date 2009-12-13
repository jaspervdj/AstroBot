/**
 * Pieter De Baets
 * Jasper Van der Jeugt
 * Groep 31
 * MoveBehaviour.h
 */
#ifndef MOVEBEHAVIOUR_H
#define MOVEBEHAVIOUR_H

#include "Behaviour.h"
#include "ObstacleEventListener.h"

/**
 * Behaviour that reacts when the robot can move.
 */
class MoveBehaviour: public Behaviour,
        public ObstacleEventListener
{
    public:
        /**
         * Constructor.
         */
        MoveBehaviour(Map *map);

        /**
         * Destructor.
         */
        virtual ~MoveBehaviour();

        /* Implementation. */
        bool isActive();

        /* Implementation. */
        void obstacleDetected(const ObstacleEvent &event);

        /* Implementation. */
        void noObstacle();

        /* Implementation. */
        void action();

     private:
        /** Map the robot is on. */
        Map *map;
    
        /** Flag to see if this behaviour is active. */
        bool active;
};

#endif
