#ifndef UNTITLED_START_MENU_H
#define UNTITLED_START_MENU_H

#endif //UNTITLED_START_MENU_H
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cstring>
#include<ctime>
#include <fstream>
using namespace std;

class menu {

public:
    void NewGame();			    //Function to create a new game
    void FastGame();		    //Function for a quick game

protected:

};

class option:public menu {
public:
    bool sound();			    //Function for sound
    int map_lenght();	        //Function to manage the length of the map
    char level();		    	//Function to set the difficulty level
    void credits();		        //Function that prints credits
    void rules();			    //Function that prints the rules on screen
    bool exit();			    //Function that
};



void create_player ();
