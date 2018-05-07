#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H

#endif //UNTITLED_PLAYER_H
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cstring>
#include<ctime>
using namespace std;
#define CONST 3

class player {

public :
    player(player *next);
    //Constructor for new player
    char insert_name();				//Function to enter the name
    int insert_age();				//Function to enter the age
    int blocked(int n);				//Function for the block
    int dice();				    	//Function for rolling the dice
    void move();					//Function for move player

    player *next;

protected :
    char name[CONST];				//Player name 3 chars
    int age;					    //Player age
    int stop;				    	//Connection with cards and boxes to stop


};

typedef player* ptr_player;			//create pointer type variables
