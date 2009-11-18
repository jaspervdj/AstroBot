#include <iostream>
#include <stdlib.h>
#include <string>

#include "Map.h"
#include "Robot.h"
#include "BinarySearchTree.h"

using namespace std;

void run(const string &fileName)
{
    Map m = Map(fileName);

    Robot r = Robot();
    m.setRobot(&r);
    
    BinarySearchTree<int, int> *test = new BinarySearchTree<int, int>();

    //initialiseer Behaviours en EventListeners

    //registreer Behaviours en EventListeners

    //start Subsumption
    /*while(!r.getDestinationReached()) {
        m.refresh();

        Behaviour* b = r.getFirstActiveBehaviour();

        b->action();
    }*/
}

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        cerr << "Syntax: AstroBot <map>" << endl;
        return 1;
    }
    else
    {
        // verwacht fileName van de in te laden map als argument!
        run(string(argv[1]));
        return 0;
    }
}