/* Authors:	Davide Balestra
*		Andrea D'Arpa
*
*  Description:	Implementation of of Map class
*/

#include "map.h"

	Map::Map(bool mode){
		if(!mode)
			cout <<"Bravo stai creando una mappa nella modalità facile";
		else
			cout <<"Bravo stai creando una mappa in modalità difficile";	
	}
