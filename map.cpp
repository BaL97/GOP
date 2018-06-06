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

	void Map::setLength(int l){
		this->length=l;
	}

	int Map::getLength(){
		return this->length;
	}

	void Map::generateMap(bool mode){
		Box *p=this->init;	//create end box as next of init
		p->next=new End();
		p=p->next;
		p->prev=this->init;		//link data structures
		//calculations of number of boxes and empty boxes (using mode parameter)
		setLength(this->calcNBox(mode));
		int e= this->HowEmpty(mode)*(this->getLength())/100;
		for(int n=this->getLength();n>2;n--){
			cout << n<<endl;
		}	
		getchar();
	}

	int Map::calcNBox(bool mode){
		srand(time(nullptr));	
		if(!mode){	//easy mode -> map length between 40-63
			return (rand() % 24 + 40);
		}
		else		//hard mode -> map length between 64-90
			return (rand() % 27 + 64);
	}
	
	int Map::HowEmpty(bool mode){
		srand(time(nullptr));	
		if(!mode){		//easy Empty box perc range between 36 and 50%
			return (rand() % 15 + 36);			
		}
		else			//hard Empty box perc range between 20 and 35%
			return (rand() % 16 + 20);
	}
