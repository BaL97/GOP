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
	
	void Map:: setAvg(int a){
	 	this->avg=a;
	}
	
	int Map::getAvg(){
		return this->avg;
	}
	
	void Map::setNEmpty(int n){
		this->nEmpty=n;
	}

	int Map::getNEmpty(){
		return this->nEmpty;
	}

	int Map::testRand(){
		int a;
		a= rand()%100+1;
		return a;
	}

	void Map::generateMap(bool mode){
		Box *p=this->init;	//create end box as next of init
		p->next=new End();
		p=p->next;
		p->prev=this->init;		//link data structures
		//calculations of number of boxes and empty boxes (using mode parameter)
		this->setLength(this->calcNBox(mode));
		this->setAvg(this->HowEmpty(mode));
		this->setNEmpty(this->getAvg()*this->getLength()/100);
		int empty=this->getNEmpty();

		//now generate the middle boxes and connects them into the map
		for(int i=this->getLength();i>2;i--){
			cout <<i <<"-";
			Box *tmp=genBox();
			cout <<tmp->getId() <<"-" <<tmp->getName() <<endl;
			if(tmp->getId()==2)	empty--;
		}
		cout <<endl <<"numero di caselle vuote rimanenti: " <<empty <<endl;	
		getchar();
	}

	int Map::calcNBox(bool mode){
		if(!mode){	//easy mode -> map length between 40-63
			return (rand() % 24 + 40);
		}
		else		//hard mode -> map length between 64-90
			return (rand() % 27 + 64);
	}
	
	int Map::HowEmpty(bool mode){
		if(!mode){		//easy Empty box perc range between 36 and 50%
			return (rand() % 15 + 36);			
		}
		else			//hard Empty box perc range between 20 and 35%
			return (rand() % 16 + 20);
	}

	Box* Map::genBox(){
		Box *n;
		int a;
		int i= rand() % 100 + 1;	//estraction of the number for the probability cases
		if(i <= this->getAvg()){
			n = new Box();
		}
		else{
			a = rand() % 6 + 3;
			switch (a){
				case 3:
					n=new Draw();
					break;
				case 4:
					n=new Bridge();
					break;
				case 5:
					n=new Prison();
					break;
				case 6:
					n=new Inn();
					break;
				case 7:
					n=new Labirinth();
					break;
				case 8:
					n=new Skull();
					break;
				default: 
					cout <<"Si e' verificato un errore inaspettato" <<endl <<"Premere un tasto per continuare . . .";
					getchar();
					break;
			}
		}
		return n;
	}
