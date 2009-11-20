#ifndef SIMULATION_H
#define SIMULATION_H

#include <string>

class Map;
class Robot;

/**
 * Main class driving the simulation.
 */
class Simulation
{
    public:
        /**
         * Constructor.
         * @param fileName File name for the map used in the simulation.
         */
        Simulation(const std::string &fileName);

        /**
         * Destructor.
         */
        ~Simulation();

        /**
         * Run the simulation.
         */
        void run();

    private:
        /** Map of the simulation. */
        Map *map;

        /** Robot in the simulation. */
        Robot *robot;
};

#endif
