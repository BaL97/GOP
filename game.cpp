/*GAME.CPP
*corpo della classe Game. Qui verra' implementata la partita.
*	AUTHORS:
*		Andrea D'Arpa				0000
* 		Davide Balestra				0000
*/

#include "game.h"
const string start_s ="®";
const string end_s ="©";
const string empty_s ="○";
const string busy_s ="●"; 
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
		
		this->initMap();
		this->parseMap();
		this->printMap();getchar();
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
	
	void Game::printMap(){
		for(int i=0;i<NLENGTH;i++){
			for(int j=0;j<MLENGTH;j++)
				cout <<this->graphicMap[i][j];
			cout <<endl;
		}
	}

	void Game::parseMap(){
		Box* p = this->map->init;
		int length = this->map->getLength()/4;
		int i=0;
		int j=0;
		bool alt = true;		//flag to discriminate the order of insert
		while(p->next!=NULL){		//END box will be treated differently (as START BOX have been to)
		//discriminating row lenght
		//first row: Map_lenght/4 
			if(alt){
				for(int k=0; k<length; k++){ 		//checking if some player is in the box yet
					if(p->next!=NULL){ 
						if (this->isBusy(p)) this->graphicMap[i][j]=busy_s;
						else this->graphicMap[i][j]=empty_s;
						j++;
						p=p->next;
					}
				}
				//if we have element to insert but length is 1 continue one by one
				i++;
				j--;				
				this->graphicMap[i][j]="|";	//PRINTING LINE SEPARATOR.
				i++;
			alt=false;
			}		//Left to Right Print
			else{
				for(int k=0;k<length;k++){
					if(p->next!=NULL){
						if (this->isBusy(p)) this->graphicMap[i][j]=busy_s;
						else this->graphicMap[i][j]=empty_s;
						j--;
						p=p->next;
					}
				}
				i++;
				j++;
				this->graphicMap[i][j]="|";
				i++;
			alt=true;
			}
		if(length!=1)	length--;
		}
		//now we are in the last element
		this->graphicMap[i][j]=end_s;
		i=i+2;
		this->graphicMap[0][0]=start_s;
		for(j=0;j<MLENGTH;j++){
			this->graphicMap[i][j]="#";
		}

	}

	void Game::initMap(){
		for(int i=0;i<NLENGTH;i++){
			for(int j=0;j<MLENGTH;j++)
				this->graphicMap[i][j]=" ";
		}
	}

	bool Game::isBusy(Box *b){
		Player *tmp = this->player->next;  		//POINT FIRST PLAYER (NOT CONSIDERING SENTINEL)
		for (int i=0; i<this->getPlayer_n(); i++){
			if (tmp->position == b)
				return true;
			tmp=tmp->next;
		}
		return false;
	}	

	void Game::gameStart(){
		Player *p = this->player->next;			//saving the first player of the list. . .
		string winner;
		while (!this->isBusy(this->map->end)){		//continue to iterate while a player reach END BOX
			this->parseMap();
			this->printMap();
			if(p->getTurn()==0)
				p->Turn();
			else {	cout <<p->getName()<<" Salta il turno";getchar();system("clear");
				p->setTurn(p->getTurn()-1);}
				//handle the lock/skip a tourn state
			winner=p->getName();			//tieni traccia per stampare il vincitore
			p=p->next;
			if (p->getTurn()==-1) p=p->next;	//handle the sentinel: it will be skipped
			cout <<"MAP LENGTH--->" <<  this->map->getLength()<<endl;
		}	
		cout<<"BRAVO -"<<winner << "- HAI VINTO!";
		cout <<endl<<"PARTITA TERMINATA"<<endl<<"premere un tasto per tornare al menu . . .";
		getchar();							//handle end game
		system("clear");	
	}
