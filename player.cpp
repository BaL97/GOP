#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cstring>
#include<ctime>
#include "player.h"
using namespace std;

char player::insert_name() {
	cout << "Il tuo nome ti identifia nel gioco. Puo essere lungo max 3 caratteri."<<endl;
	cout << "Inserisci il tuo nome: "<<endl;
	for (int i=0; i<CONST ;i++) 
		cin >> name[i]; 
		
	return name[CONST];			//Return the name
	//warning: array index 3 is past the end of the array (which contains 3 elements) [-Warray-bounds]
}

int player::insert_age() {
	cout << "Il giocatore più piccolo inizia."<<endl;
	cout << "Inserisci la tua età:"<<endl;
	cin >> age;
	
	return age;				//Return the age
}

int player::blocked(int n) {
	stop = n;
	
	return stop;				//Return to the inside (the number of turns remaining locked)
}

int player::dice() {				//Function for throwing the dice
						//The dice are two, in value it is stored in a sum_dadi 
	int dado1 = (rand() % 6) + 1;
	int dado2 = (rand() % 6) + 1;
	
	int sum_dadi = dado1+dado2;		//To recall the value in case of equal movements
	cout << "Dado uno: " << dado1 << ". Dado due: " << dado2 << ". Ti muoverai di " << sum_dadi << " caselle." << endl;
	
	return (sum_dadi);			//Return the sum
	
}

void player::move() {
	
}
