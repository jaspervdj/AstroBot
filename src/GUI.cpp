#include "GUI.h"
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

void GUI::initialize(const string & fileName)
{
    stringstream cmds;
    cmds << "java Show " << PORT_NR << " LOAD " << fileName << endl;
    system(cmds.str().c_str());
}

void GUI::show(Command cmd)
{
    stringstream cmds;
    cmds << "java Show " << PORT_NR << " " ;
    if(cmd == MOVE) 
    {
        cmds << "MOVE";
    } else if (cmd == ROTATE)
    {
        cmds << "ROTATE";
    } else if (cmd == JUMP)
    {
        cmds << "JUMP";
    } else if (cmd == SHOOT)
    {
        cmds << "SHOOT";
    }
    cmds << endl;
    system(cmds.str().c_str());
}
