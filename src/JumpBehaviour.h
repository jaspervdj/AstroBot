/**
 * Pieter De Baets
 * Jasper Van der Jeugt
 * Groep 31
 * JumpBehaviour.h
 */
#ifndef JUMPBEHAVIOUR_H
#define JUMPBEHAVIOUR_H

#include "Behaviour.h"
#include "ObstacleEventListener.h"

/**
 * Behaviour that reacts when the robot can jump.
 */
class JumpBehaviour: public Behaviour,
        public ObstacleEventListener
{
    public:
        /**
         * Constructor.
         */
        JumpBehaviour(Map *map);

        /**
         * Destructor.
         */
        virtual ~JumpBehaviour();

        /* Implementation. */
        bool isActive();

        /* Implementation. */
        void obstacleDetected(const ObstacleEvent &event);

        /* Implementation. */
        void noObstacle();

        /* Implementation. */
        void action();

    private:
        /** Limited memory. */
        Obstacle *lastJumpableObstacle;

        /** Map the robot is on. */
        Map *map;

        /** Robot to control. */
        Robot *robot;
    
        /** Flag to see if this behaviour is active. */
        bool active;
};

#endif
