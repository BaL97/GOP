#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cstring>
#include<ctime>
using namespace std;
#define CONST 3

class player {

	public :
		player (char NomeGiocatore[CONST], int eta){strcpy (Name,NomeGiocatore); Age = eta ;}	
								//Constructor for new player 
		
	protected :
		char Name[CONST];				//Player name 3 chars
		int Age;					//Player age

		bool Blocco(int stop);				//Connection with cards and boxes to stop
		int Dice();					//Function for rolling the dice
		void Move();					//Function for move player	
					
};

typedef player* ptr_player;					//create pointer type variables
