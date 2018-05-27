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
		this->mazzo = new Mazzo();
		this->mazzo->Mischia();
		//i puntatori degli oggetti da impementare saranno inizializzati a Null
	}
//setter
	
//getter
