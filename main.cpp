/* Authors:	Davide Balestra: 0000789078
 * 		Andrea D'Arpa:	 0000803520
 * Main file of GOP Project, include the main menu and the access of Game's functions
 */
#ifndef GOP_DEF
#define GOP_DEF
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include <ctime>
#include <fstream>
#include "menu.h"
#endif

using namespace std;

int main(){
    char a;
	Menu m;
	cout <<"Benvenuto in GOP! (Gioco dell'Oca Pazza)" <<endl;
    //The menu will continues to show up until the user will choice to exit the game (q)
    
    while(true){
        m.display();
        cin>>a;
        m.setX(a);
        m.choice();
    }
}
