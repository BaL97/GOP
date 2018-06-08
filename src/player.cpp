/* 	Authors:	 Davide Balestra
			 Andrea D'Arpa
			 Matteo Celani

	Description: Implements the player class
*/

#include "player.h"


//Default constructor-> only for sentinel element 
Player::Player(){	
	this->next=NULL;
	this->setName("");
	this->setAge(0);
	this->setTurn(-1);
	this->position=NULL;
	this->setNBox(1);
}

//Constructor with parameters
Player::Player(string n, int a, Box *p){
	this->next=NULL;
	this->setName(n);
	this->setAge(a);
	this->setTurn(0);
	this->position=p;	//set her the start cell
	this->setNBox(1);
}

//Setters
void Player::setName(string n){
	this->name=n;
}

void Player::setAge(int a){
	this->age=a;
}

void Player::setTurn(int t){
	this->turn=t;
}

void Player::setNBox(int x){
	this->nBox=x;
}

void Player::setDice(int n){
	this->d=n;
}
//implents here the set cell method

//Getters
string Player::getName(){
	return this->name;
}

int Player::getAge(){
	return this->age;
}

int Player::getTurn(){
	return this->turn;
}

int Player::getNBox(){
	return this->nBox;	
}

int Player::getDice(){
	return this->d;
}
//implements here the get cell method


void Player::Turn(Mazzo *m){
	Box *b=this->position;		//saving tmp the initial position before the turn (for handling labirinth)
	int i=this->getNBox();		//saving initial nbox (handling labirinth)
	cout<< "E' IL TURNO DI: "<<this->getName()<<endl;
	cout << "Premere invio per premere il dado . . .";
	getchar();
	this->setDice(this->dice());
	//incrementi nbox e spostamento puntatore a mappa del pg
	this->move(this->getDice(),false);
	cout<<"WOW! hai tirato un bel "<<this->getDice()<<endl;
	this->action(m);
	if(this->position->getId()==7)	{
		this->position=b;	//restore intial position and nBox if player is in labirinth
		this->setNBox(i);
	}
	cout << "FINE DEL TURNO DI " <<this->getName()<<" PREMERE INVIO!";
	getchar();
	system("clear");
}

int Player::dice(){
int x;
x=rand()% 6 + 1;
return (x+rand()%6+1);
}

void Player::move(int x, bool v){	//if v is 0, move straight, else move backward
//prende un personaggio e sposta il suo puntatore a casella di posizione rispetto al tiro di dadi
//aggiorna il parametro position e il parametro nBox
	for(x; x>0; x--){
		if ((this->position->getId() != 1)&&(!v)){	
			//muovi avanti solo se non sei in casella finale e v non è true
			this->position= this->position->next;
			this->setNBox(this->getNBox()+1);
		}
		else if (this->position->prev!=NULL){					//sei andato oltre end box. torna indietro, solo se, Manage the back movement if we are in start  
			this->position=this->position->prev;
			this->setNBox(this->getNBox()-1);
			v=true;
		}
	//gestire limite di move back a start
	}
}

//now implements the action method for each subclass
void Player::action(Mazzo *m){
	Carte c;
	this->position->display();
	switch(this->position->getId()){
		case 3:	//Draw Box
			//cout <<m->getSegnalino();getchar();
			c=m->Pesca();
			c.messaggio();
			this->handleCard(c,m);
			break;		
		case 4:	//Bridge Box
			//Call movement to the player
			this->move(this->getDice(),false);
			this->action(m);		//itera l'azione alla casella in cui si trova adesso
			break;
		case 5:	//Prison Box
			this->setTurn(3);
			break;
		case 6:	//Inn Box
			this->setTurn(1);
			break;
		case 7:	//Labirinth Box+
			//handled in turn
			break;
		case 8:	//Skull Box
			this->move(this->getNBox()-1,true);
			break;
		default:
			break;
	}
}

void Player::handleCard(Carte c, Mazzo *m){
	string s="";
	switch(c.getId()){
		case 0:	//empty card
			break;
		case 1:	//move card
			this->move(1,false);	//move straight of 1 box
			this->action(m);
			break;
		case 2: //Blocked Card
			this->setTurn(1);	//block for 1 turn
			break;
		case 3: //Throw straight
			cout <<"premere invio per tirare i dadi . . .";
			getchar();
			this->setDice(this->dice());
			cout <<"WOW! hai tirato un bel " <<this->getDice()<<endl;
			this->move(this->getDice(),false);	//throw dice and move straight
			this->action(m);
			break;
		case 4: //throw back
			cout <<"premere invio per tirare i dadi . . .";
			getchar();
			this->setDice(this->dice());
			cout <<"WOW! hai tirato un bel "<<this->getDice()<<endl;
			this->move(this->getDice(),true);	//throw dice and move backward
			this->action(m);
			break;
		case 5:	//back to start a player
			Player *app=this->next;
			if(app->getAge()==0)	app=app->next;	//skipping the sentinel
			app->move(app->getNBox()-1,true);		//next player goes to start box
			break;
	}
}
