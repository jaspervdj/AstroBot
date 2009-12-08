#include <iostream>
#include <stdlib.h>
#include <string>

#ifdef WIN32
#include <crtdbg.h>
#endif

#include "Map.h"
#include "Robot.h"

#include "DestinationReachedBehaviour.h"
#include "JumpBehaviour.h"
#include "ShootBehaviour.h"
#include "BadnessBehaviour.h"
#include "MoveBehaviour.h"
#include "TurnBehaviour.h"

using namespace std;

int main(int argc, char** argv)
{
    if(argc != 2) {
        cerr << "Syntax: AstroBot <map>" << endl;
        return 1;
    } else {
        /* Map of the simulation. */
        Map map(argv[1]);

        /* Robot in the simulation. */
        Robot robot;
        map.setRobot(&robot);

        /* Create behaviours. */
        const int numberOfBehaviours = 6;
        Behaviour *behaviours[numberOfBehaviours] = {
            new DestinationReachedBehaviour(&map, &robot),
            new JumpBehaviour(&map, &robot),
            new ShootBehaviour(&map, &robot),
            new BadnessBehaviour(&map, &robot),
            new MoveBehaviour(&map, &robot),
            new TurnBehaviour(&map, &robot)
        };

        /* Initialize behaviours. */
        for(int i = 0; i < numberOfBehaviours; i++) {
            map.registerListener(behaviours[i]);
            robot.registerBehaviour(behaviours[i]);
        }

        /* Run subsumption. */
        while(!robot.isDestinationReached()) {
            map.refresh();
            Behaviour *behaviour = robot.getFirstActiveBehaviour();
            if(behaviour) {
                behaviour->action();
            } else {
                class NoActiveBehaviourException: public exception
                {
                    const char *what()
                    {
                        return "No active behaviour found.";
                    }
                };

                throw NoActiveBehaviourException();
            }
        }

        /* Free behaviours. */
        for(int i = 0; i < numberOfBehaviours; i++) {
            delete behaviours[i];
        }

        #ifdef WIN32
        _CrtDumpMemoryLeaks();
        #endif

        return 0;
    }
}
