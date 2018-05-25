/* Author: 	Davide Balestra
 * 		    Andrea D'Arpa
 * Description: Header file of class Menu
 */
#ifndef GOP_DEF
#define GOP_DEF
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#endif

using namespace std;

class Menu{
protected:
    int x;
    int Player_n;       	//Number of players (>1)
    int Map_l;          	//MAP LENGHT (>=63)
    bool Sound;        	 	//Active sound
    bool Mode;          	//difficulty parameter false = EASY || true = HARD
    ifstream file_in;		//stream for input file
    char parser;		//string for parsing files

public:
    
    /* Default Constructor: default configuration:
     * x=
     * Player_n=2;                  will be setted in NewGame menu option
     * sound = true;
     * Map_l = 63;
     * Mode = false;
     */
     Menu();
	 Menu(int pn, int m, bool s, bool mo);
    
    //set methods
    void setX(int x);
    void setPlayer_n(int n);
    void setSound(bool n);
    void setMapLenght(int n);
    void setMode(bool n);
    
    //get methods
    int getX();
    int getPlayer_n();
    bool getSound();
    int getMapLenght();
    bool getMode();
    void displayAll();
    
     //display the menu options
     void display();
	 
     //switch the choice of user
     void choice();
	 
     //setting options inside the menu
     void setOptions();

     //parsing input files method
     void parseFile(string name);
};
