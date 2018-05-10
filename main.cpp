/* Authors:	Davide Balestra: 0000789078
 * 		    Andrea D'Arpa:	 0000803520
 * Main file of GOP Project, include the main menu and the access of Game's functions
 */
#ifndef GOP_DEF
#define GOP_DEF
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include <string>
#include <sstream>
#include <ctime>
#include <fstream>
#include "menu.h"
#define const INT_MAX 5;
#endif

using namespace std;

int main(){
    std::string s;
    int x;
	Menu m;
	cout <<"Benvenuto in GOP! (Gioco dell'Oca Pazza)" <<endl;
    //The menu will continues to show up until the user will choice to exit the game (q)
    
    while(true){
        m.display();
        //the input is made parsing a string to an integer so we can handle input errors
        //not valid string (not numbers) will not be accepted
        //string relatives to double/float values will take as integer (casting by truncation)
        getline(cin,s);
        x=atoi(s.c_str());
        m.setX(x);
        m.choice();
    }
}
