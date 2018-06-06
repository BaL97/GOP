/*
* 	Authors:	Davide Balestra
*			Andrea D'Arpa
*
*	Description:	Header file of class Map
*/

#include "player.h"
class Map{
public:
	Start *init;		//Start Box (first of the map)
	Map(bool mode);		//Create the map (Hard/Easy MODE)
	void generateMap(bool mode);
	int calcNBox(bool mode);
};
