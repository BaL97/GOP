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
		Box *p;	//create end box as next of init
		this->end=new End();
		this->init->next=this->end;
		this->end->prev=this->init;		//link data structures
		//calculations of number of boxes and empty boxes (using mode parameter)
		this->setLength(this->calcNBox(mode));
		this->setAvg(this->HowEmpty(mode));
		this->setNEmpty(this->getAvg()*this->getLength()/100);
		int empty=this->getNEmpty();
		p=this->init;
		//now generate the middle boxes and connects them into the map
		for(int i=this->getLength();i>2;i--){
			if(empty==i-2){
				Box *s;
				p=this->init;
				for(i;i>2;i--){
					s=p->next;
					p->next=new Box();
					p->next->next=s;
					s->prev=p->next;
					p->next->prev=p;
					p=p->next;
					empty--;
				}	
			}
			else{
				Box *tmp=genBox();	//generate the box
				if(tmp->getId()==2){
					if(empty!=0)	empty--;
					else{	//this provide to not insert more empty boxes then Nempty calculated before
						while(tmp->getId()==2)	tmp=genBox();
					}
				}
				p->next=tmp;
				tmp->prev=p;
				tmp->next=this->end;
				this->end->prev=tmp;
				p=p->next;
			}
		}
		
		p=this->init;
		while(p!=NULL){
			cout << p->getName()<<" "<<p->graphicBox[0] << p->graphicBox[1] << p->graphicBox[2] << endl;
			p=p->next;
		
		}getchar();
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
