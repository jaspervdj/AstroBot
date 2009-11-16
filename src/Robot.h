#ifndef ROBOT_H
#define ROBOT_H

#include "Orientation.h"
#include <list>

class Behaviour;

/** Class to represent the robot. */
class Robot
{
    public:
        /**
         * Constructor.
         */
        Robot();

        /**
         * Destructor.
         */
        ~Robot();

        /**
         * See if the robot has reached it's destination.
         * @return If the robot has reached it's destination.
         */
        bool isDestinationReached() const;

        /**
         * Set the robot destation reached status.
         * @param destinationReached Has the robot reached it's destination?
         */
        void setDestinationReached(bool destinationReached);

        /**
         * Get the speed of the robot.
         * @return The speed of the robot.
         */
        int getSpeed() const;

        /**
         * Set the speed of the robot.
         * @param speed The new speed for the robot.
         */
        void setSpeed(int speed);

        /**
         * Get the orientation of the robot.
         * @return The orientation of the robot.
         */
        Orientation getOrientation() const;

        /**
         * Set the orientation for the robot.
         * @param orientation The new orientation for the robot.
         */
        void setOrientation(Orientation orientation);

        /**
         * Add a behaviour for this robot.
         * @param behaviour Behaviour to add.
         */
        void registerBehaviour(Behaviour *behaviour);

        /**
         * Get the first active behaviour of this robot.
         * @return The first active behaviour for this robot.
         */
        Behaviour *getFirstActiveBehaviour();

    private:
        /** Has the robot reached it's destination? */
        bool destinationReached;

        /** Speed of the robot. */
        int speed;

        /** Orientation of the robot. */
        Orientation orientation;

        /** List with the robot's behaviours. */
        std::list<Behaviour*> behaviours;
};

#endif
