/*GAME.H
*header della classe Game. Qui verra' implementata la partita.
*	AUTHORS:
*	Andrea D'Arpa				0000
* 	Davide Balestra				0000
*/

#include "menu.h"
#include "Mazzo.h"
#include "player.h"

using namespace std;

class Game:public Menu{
protected:
	//i parametri di numero giocatori sono ereditati dalla classe madre Menu
	
	
	/* I PARAMETRI QUI DEFINITI SONO ANCORA DA IMPLEMENTARE!
			player (la classe deve contenere un puntatore al primo el della lista. Inizializzato a NULL prima di entrare in NewGame(). )
			mazzo  (puntatore alla prima carta del mazzo)
			mappa  (puntatore alla prima casella della mappa.)
	
	*/

public:
	Mazzo *mazzo;
	Player *p;
//constructors:
	Game();								//costruttore di default
	Game(int p, bool mo, bool s);		//costruttore con parametri rispettivamente: giocatori, mappa, modalità e  suono.

//da implementare set e get degli oggetti da implementare
	
	//Method that creates a list of player (knowing player's number)
	void createPlayers();
};
