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
		
		this->parseMap();

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
	
	void Game::stampaa(){
		cout <<start_s<<end_s<<empty_s<<busy_s<<empty_s;
		getchar();
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
		this->graphicMap[0][0]=start_s;
		int length = this->map->getLength()/4;
		int i=0;
		int j=1;
		bool alt = true;		//flag to discriminate the order of insert
		while(p->next!=NULL){		//END box will be treated differently (as START BOX have been to)
		//discriminating row lenght
		//first row: Map_lenght/4 
			if(alt){
				for(j; j<length; j++){ 		//checking if some player is in the box yet
					if(p->next==NULL)	break;
					else	{p=p->next;
					this->graphicMap[i][j]=empty_s;
					//if (p->isBusy()) this->graphicMap[i][j]=busy_s;
					//else this->graphicMap[i][j]=empty_s;
					}
				}
				if(length!=1) length--;	//if we have element to insert but length is 1 continue one by one
				i++;
				j--;				
				this ->graphicMap[i][j]="|";	//PRINTING LINE SEPARATOR.
				i++;
			cout << "Alt";getchar();
			alt=false;
			}		//Left to Right Print
			else{
				for(int k=0;k<length;k++){
					if(p->next==NULL)	break;
					else {
						p=p->next;
						this->graphicMap[i][j]=empty_s;
						//if (p->isBusy()) this->graphicMap[i][j]=busy_s;
						//else this->graphicMap[i][j]=empty_s;
						j--;
					}
				}
				if(length!=1) length--;
				i++;
				j++;
				this->graphicMap[i][j]="|";
				i++;
			alt=true;
			cout <<"NO";getchar();
			}
		}
		//now we are in the last element
		this->graphicMap[i][j]=end_s;	
		}
	
