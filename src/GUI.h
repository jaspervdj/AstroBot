#ifndef GUI_H
#define GUI_H
 
#include <string>

class GUI
{
public:

	static const int PORT_NR = 20910; 

	enum Command 
	{
		MOVE, //laat de robot _1_ cel voorwaarts bewegen
		ROTATE, //laat de robot een kwartslag met de klok meedraaien
		JUMP, //laat de robot over de volgende cel springen
		SHOOT //vernietigd het obstakel net voor de robot
	};

	//Initializes the GUI with the map in the specified file.
	static void initialize(const std::string & file_name);

	//Shows the effects of the specified command.
	static void show(Command cmd);

};

#endif /* GUI_H */