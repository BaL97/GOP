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
		
		//Create the map Now
		this->map=new Map(this->getMode());

		//Now create Mazzo -> OK!
		this->mazzo = new Mazzo();
		this->mazzo->Mischia();
		
		//Now create Players List -> OK
		this->player=new Player(); //create the sentinel
		createPlayers(); //now init the players list


		//i puntatori degli oggetti da impementare saranno inizializzati a Null
	}

	void Game::createPlayers(){
		string n;
		string a_string;
		int a;
		//Save the tmp pointer
		Player *tmp=NULL;
		Player *p=NULL;
		int i=this->Player_n;		//save the tmp player number
		do{
			cout <<"Nome: ";	//get the parameters
			getline(cin,n);
			do{
				cout <<"Eta': ";
				getline(cin,a_string);
				a=atoi(a_string.c_str());
				if(a<1) {
					cout <<"Eta' non valida, reinserire" <<endl <<"Premere un tasto per continuare . . .";
					getchar();
				}
			}while(a<1);

			tmp=new Player(n,a,(this->map)->init);	//instances the new player as next of the current
			p=sortInsert(tmp);
			tmp=NULL;
			i--;
		}while(i>0); //until Players Number is not 0
		p->next=this->player;	//ciclic list to control the turns
		system("clear");
	}


	Player* Game::sortInsert(Player *p){
		Player *curr=this->player;
		Player *prec=curr;
		bool flag=false;
		
		while(curr!=NULL){	
			if((p->getAge()<curr->getAge()) && (!flag)){
				flag=true;
				prec->next=p;
				p->next=curr;
			}
			prec=curr;
			curr=curr->next;	
		}
		if(!flag){
			prec->next=p;
			return p;
		}
		else	return (prec);
	}

	void Game::displayPlayers(){
	//scan the list and print players
	Player *tmp;
	tmp =this->player->next;
	for(int i=0; i<this->Player_n; i++){
		cout <<tmp->getName() <<"-" <<tmp->getAge() <<"-" <<tmp->position->getName() <<"-" <<tmp->position->next->getName()  <<"-";
		cout << tmp->position->next->prev->getName() <<endl;
		tmp=tmp->next; 
		}
	}

	void Game::displayMap(){
		for(int i=0;i<MLENGTH;i++){
			for(int j=0;j<MLENGTH;j++)
				cout <<this->graphicMap[i][j];
			cout <<endl;
		}
	}
