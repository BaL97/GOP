/*GAME.H
*header della classe Game. Qui verra' implementata la partita.
*	AUTHORS:
*	Andrea D'Arpa				0000
* 	Davide Balestra				0000
*/

#include "menu.h"
#include "Mazzo.h"
#include "map.h"
const int MLENGTH =25;
const int NLENGTH=15;
using namespace std;


class Game:public Menu{
protected:
	//i parametri di numero giocatori sono ereditati dalla classe madre Menu
	string graphicMap[NLENGTH][MLENGTH];	

public:
	Map *map;
	Mazzo *mazzo;
	Player *player;
//constructors:
	Game();								//costruttore di default
	Game(int p, bool mo, bool s);		//costruttore con parametri rispettivamente: giocatori, mappa, modalità e  suono.

//da implementare set e get degli oggetti da implementare
	
	//Method that creates a list of player (knowing player's number)
	void createPlayers();
	Player* sortInsert(Player *p);
	void displayPlayers();
	void parseMap();	//parse the list and update the graphc map
	void printMap();
	void initMap();		//initialize the matrix with empty strings
	bool isBusy(Box *b);
	void gameStart();
};
