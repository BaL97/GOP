#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cstring>
#include<ctime>
#include "player.h"
using namespace std;

bool player::Blocco(int stop) {			//function to stop the player if the card or the box
	if (stop == 0)				//has a value that is equal to 0 (ie, do not move)
	return false;				//the function returns false
}

int player::Dice() {				//function for throwing the dice
						//the dice are two, in value it is stored in a sum_dadi 
	int dado1 = (rand() % 6) + 1;
	int dado2 = (rand() % 6) + 1;
	
	int sum_dadi = dado1+dado2;		//to recall the value in case of equal movements
	return (sum_dadi);			//return the sum
	
}

void player::Move() {
	
}
