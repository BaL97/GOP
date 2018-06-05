/*GAME.CPP
*corpo della classe Game. Qui verra' implementata la partita.
*	AUTHORS:
*		Andrea D'Arpa				0000
* 		Davide Balestra				0000
*/

#include "game.h"

	Game::Game():Menu(){									//costruttore di default
		
		//i parametri ereditati verranno inizializzati dal costruttore di menu
		
		//i puntatori degli oggetti da impementare saranno inizializzati a Null
	}
	Game::Game(int p, bool mo, bool s):Menu(p, mo, s){		//costruttore con parametri rispettivamente: giocatori, mappa, modalità e  suono.
		//i parametri ereditati verranno inizializzati dal costruttore di menu
		
		//Now create Mazzo -> OK!
		this->mazzo = new Mazzo();
		this->mazzo->Mischia();
		
		//Now create Players List ->
		this->player=new Player(); //create the sentinel
		createPlayers(); //now init the players list


		//i puntatori degli oggetti da impementare saranno inizializzati a Null
	}

	void Game::createPlayers(){
		string n;
		int a;
		//Save the tmp pointer
		Player *p=this->player;
		Player *tmp=NULL;
		Player *prc=p;
		int i=this->Player_n;		//save the tmp player number
		do{
			cout <<"Nome: ";	//get the parameters
			cin >>n;
			cout <<"Eta': ";
			cin >>a;
			p->next=new Player(n,a);	//instances the new player as next of the current
			if(p->getAge()>a){
				tmp = p;
				prc->next = tmp->next;
				prc->next->next = tmp;
				tmp->next=NULL;
				prc=prc->next;
			}else p=p->next;
			i--;
		}while(i>0); //until Players Number is not 0
		p->next=this->player;	//ciclic list to control the turns
	}
	
	void Game::displayPlayer(){
	Player *tmp;
	tmp =this->player->next;
	for(int i=0; i<this->Player_n; i++){
		cout<< tmp->getName()<< " " << tmp->getAge()<<endl;
		tmp=tmp->next; 
		}
	}
	
	

