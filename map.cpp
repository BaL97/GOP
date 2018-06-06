/* Authors:	Davide Balestra
*		Andrea D'Arpa
*
*  Description:	Implementation of of Map class
*/

#include "map.h"

	Map::Map(bool mode){
		this->init=new Start();
		generateMap(mode); //generate the map(Random)
	}

	void Map::generateMap(bool mode){
		int n=this->calcNBox(mode);		//calc the number of boxes
	}

	int Map::calcNBox(bool mode){
		srand(time(nullptr));	
		if(!mode){	//easy mode -> map length between 40-63
			return (rand() % 24 + 40);
		}
		else		//hard mode -> map length between 64-90
			return (rand() % 27 + 64);
	}
