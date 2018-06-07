/*	BOX.CPP
*	AUTHORS:
*		Andrea D'Arpa
*		Davide Balestra
*
*	DESCRIPTION:
*		Implementation of Box's class.
*/

#include "box.h"

//constructors
	Box::Box(){
		setName("0");
		setDes("0");
		setId(2);
		this->prev=NULL;						
		this->next=NULL;
		this->c=NULL;						
	}												//default constructor
	Box::Box(string n, string d, int id){			//costruttore con parametri	
		setName(n);
		setDes(d);
		setId(id);
		this->prev=NULL;						
		this->next=NULL;
		this->c=NULL;		
	}
//SETTER METHODS
	void Box::setName(string n){this->name = n;}
	void Box::setDes(string n){this->description = n;}
	void Box::setId(int n){this->id=n;}

//GETTER METHODS
	string Box::getName(){return this->name;}
	string Box::getDes(){return this->description;}
	int Box::getId(){return this->id;}

//Display box's info
	void Box::display(){
		cout <<this->getName() <<" - " <<this->getDes() <<endl;
	}
	
	//Now defining the constructor of subclasses
	Start::Start():Box("Start","Casella di partenza",0){}
	End::End():Box("End","Hai vinto",1){}
	Draw::Draw():Box("Pesca","Pesca una carta",3){}
	Bridge::Bridge():Box("Bridge","Sei fortunato, raddoppia il tuo tiro ;)",4){}
	Prison::Prison():Box("Prison","Sei finito in prigione, resta fermo tre turni :(",5){}
	Inn::Inn():Box("Inn","Ti fermi a prendere una birra in locanda, stai fermo per un turno",6){}
	Labirinth::Labirinth():Box("Labirinth","Sei perso nel labirinto, torna da dove sei venuto: ",7){}
	Skull::Skull():Box("Skull","Che paura, un TESKIOOOHHHH! Fuggi tornando all'inizio",8){}


