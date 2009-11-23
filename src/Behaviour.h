#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

class Map;

/** Abstract class defining a certain Robot behaviour. */
class Behaviour
{
    public:
        /**
         * Constructor.
         */
        Behaviour();

        /**
         * Destructor.
         */
        virtual ~Behaviour();

        /**
         * Check if this Robot behaviour wants focus.
         * @return If this robot behaviour wants focus.
         */
        virtual bool isActive() = 0;

        /**
         * Execute the behaviour action.
         */
        virtual void action() = 0;

        /**
         * Get the map for the robot.
         * @return The map this robot is on.
         */
        Map *getMap() const;

        /**
         * Set the map the robot is on.
         * @param map Map the robot is on.
         */
        void setMap(Map *map);

    private:
        /** Map the robot is on. */
        Map *map;
};

#endif
