#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cstring>
#include<ctime>
#include "start_menu.h"
using namespace std;

void menu::NewGame() {

}

void menu::FastGame() {

}

bool option::sound() {							//takes a character input to handle the sounds
	char z;								
	cout << "Vuoi attivare o disattivare i suoni ?" << endl;
	cout << "('a' per attivare 'd' per disattivare)" << endl;
	cin >> z;
	
	if (z == 'a')
		return true;						//returns true if you want to activate the sounds
	else if (z == 'd')
		return false;						//returns false if you want to disable the sounds
	else if (z != 'a' || z != 'd') {
		cout << "Errore. 'a' per attivare 'd' per disattivare" << endl;
		cout << "I suoni saranno disattivati." << endl;		//The entered character does not correspond to the choices
		return false;						//Returns false, the sounds will be deactivated
	}

}

int option::map_lenght() {						//It takes an input to handle the map
	char z;
	int lenght;
	cout << "Qui puoi gestire la mappa, scegliere la sua lunghezza (min 63; max 90)." << endl;
	cout << "Oppure scegliere se la mappa sara creata casualmente da gioco." << endl;
	cout << "Vuoi scegliere la lunghezza o crearla casualmente ?"<< endl;
	cout << "('s' per scegliere 'c' per casuale)" << endl;
	cin >> z;
	
	if ( z == 's'){
		cout << "Bene. Quanto vuoi lunga la mappa ? Min 63, max 90 : " << endl;
		cin >> lenght;						//The user chooses the length
	}
	else if ( z == 'c')	lenght = (rand() % 28) + 63;		//The length is created randomly
	else if (z != 's' || z != 'c')	{
		cout << "Errore. 's' per scegliere 'c' per casuale" << endl;
		cout << "La mappa sarà creata casualmente" << endl;	//The entered character does not correspond to the choices
		lenght = (rand() % 28) + 63;				//The length is created randomly
	}
	
	return lenght;							//returns the length of the map
}

char option::level() {							//Function that returns a character for the choice of difficulty
	char z;
	while ( z == 'c' || z == 'a') {
	cout << "Le difficoltà del gioco possono essere 2." << endl;
	cout << "Modalità classica." << endl;
	cout << "Modalità anvanzata." << endl;
	cout << "Digita 'c' per la modalità classica 'a' per la modalità avanzata." << endl;
	cin >> z;
	}
									//The function will return a character
	return z;							//c for classic a for advanced
}

void option::credits() {						//Function that makes credits read on screen

}

void option::rules() {							//Function that makes the rules read on screen

}

bool option::exit() {							//Function that makes the user choose whether to exit the game
	char z;
	int conta = 0;
	while ( z == 'S' || z == 'N' || conta <= 5) {
	cout << "Vuoi uscire dal gioco ?" << endl;
	cout << "'S' Per uscire." << endl;
	cout << "'N' Per tornare alle opzioni." << endl;
	cout << "Cosa desideri fare ?" << endl;
	cin >> z;
	
	if (z != 'S' && z != 'N') {					//If you are wrong for 'conta' times to enter the game closes
			cout << "Errore. Il carrattere inserito non corrisponde. Per favore riprova." << endl;
			conta++;
		} 
	}
	
	if (z == 'S' || conta >= 5)
		return true;						//Return true to close
	else if (z == 'N') 
		return false;						//Return false to keep open
}
