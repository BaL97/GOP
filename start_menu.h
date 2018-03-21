#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cstring>
#include<ctime>
using namespace std;

class menu {

	public:
	void NewGame();			//Function to create a new game
	void FastGame();		//Function for a quick game
	
	protected:
	
};

class option:public menu {
	public:
	bool sound();			//Function for sound
	int map_lenght();		//Function to manage the length of the map
	char level();			//Function to set the difficulty level
	void credits();			//Function that prints credits
	void rules();			//Function that prints the rules on screen
	bool exit();			//Function that stops the game and goes out
};


/* A typical example of the menu 

	Gioco dell'Oca Pazza
	
	Nuova Partita
	Partita Veloce
	Opzioni
	
*/

/* A typical example of the menu option

	Gioco dell'Oca Pazza
	
	Nuova Partita
	Partita Veloce
	
	Suoni
	Mappa
	Difficoltà
	Regole
	
	Esci
	
	Credits
	
*/

/* A typical example of the menu option with the cursor of choice 

	Gioco dell'Oca Pazza
	
	Nuova Partita
	Partita Veloce
	
	Suoni
	Mappa
>	Difficoltà	<
	Regole
	
	Esci
	
	Credits
	
*/
