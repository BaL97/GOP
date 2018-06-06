/*
* 	Authors:	Davide Balestra
*			Andrea D'Arpa
*
*	Description:	Header file of class Map
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<time.h>
#include "player.h"

using namespace std;
class Map{
public:
	Start *init;		//Start Box (first of the map)
	Map(bool mode);		//Create the map (Hard/Easy MODE)
	void generateMap(bool mode);	//generate the map depemding by its difficulty parameter
	int calcNBox(bool mode);	//calculate the number of boxes inside the map
	int HowEmpty(bool mode);	//decide the percentuage of empty boxes in the map

};
