/*GAME.H
*header della classe Game. Qui verra' implementata la partita.
*	AUTHORS:
*		Andrea D'Arpa				0000
* 		Davide Balestra				0000
*/

#include "menu.h"

using namespace std;

class Game:public Menu{
protected:
	//i parametri di numero giocatori, suono, mappa e modalità sono ereditati dalla classe madre menu
	/* I PARAMETRI QUI DEFINITI SONO ANCORA DA IMPLEMENTARE!
			player (la classe deve contenere un puntatore al primo el della lista. Inizializzato a NULL prima di entrare in NewGame(). )
			mazzo  (puntatore alla prima carta del mazzo)
			mappa  (puntatore alla prima casella della mappa.)
	
	*/

public:
//constructors:
	Game();								//costruttore di default
	Game(int p, int m, bool mo, bool s);		//costruttore con parametri rispettivamente: giocatori, mappa, modalità e  suono.


//setter

//getter
	//da implementare set e get degli oggetti da implementare
};