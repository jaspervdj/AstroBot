#ifndef ROBOT_H
#define ROBOT_H

#include "Orientation.h"
#include "Cell.h"
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
         * Get the current position.
         */
        Cell *getCurrentPosition();

        /**
         * Add the last move that was performed by the robot
         * @param cell The new position
         */
        void addNextMove(const Cell &cell);

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

    protected:
         /**
         * Set the new position of the robot
         * @param position The new position
         */
        void setCurrentPosition(Cell *cell);

    private:
        /** Has the robot reached it's destination? */
        bool destinationReached;

        /** Speed of the robot. */
        int speed;

        /** Orientation of the robot. */
        Orientation orientation;

        /** Position of the robot. */
        Cell *position;

        /** List with the taken path */
        std::list<Cell*> path;

        /** List with the robot's behaviours. */
        std::list<Behaviour*> behaviours;
};

#endif
