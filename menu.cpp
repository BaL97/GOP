/*	Author: Davide Balestra 0000789078
 *	Date: 09-05-2018
 *	Implementation of class menu
 */

#include "menu.h"
#ifndef GOP_DEF
	#define GOP_DEF
	#include <iostream>
#endif

using namespace std;

char Menu::display(){
	char x;
	cout <<"Menu" <<endl;
	cout <<" Nuova partita		(n)" <<endl;
	cout <<" Partita veloce		(v)"<<endl;
	cout <<" Opzioni		(o)" <<endl;
	cout <<endl <<"Esci dal gioco	(q)"<<endl;
	cin >> x;
	return x;
}

Menu Menu::choice(char x){
	switch(x){
		case 'n':
			//this->NewGame();
			break;
		case 'v':
			//this->FastGame();
			break;
		case 'o':
			this->ChoiceOptions();
			break;
		//Exit the game
		case 'q':
			char tmp=' ';
			while ((tmp!='s')||(tmp!='n')){
				cout <<"Sei sicuro di voler uscire da GOP?" <<endl <<"(s) Si" <<endl <<"(n) No"<<endl;
				cin >> tmp;
				switch(tmp){
					case 's':
						cout <<"Grazie per aver Giocato a GOP, alla prossima" <<endl;
						cout <<"Premere un tasto per continuare . . .";
						getchar();getchar();
						exit(1);
						break;
					case 'n':
						//clear
						this->choice(this->display());
						break;
					default:
						cout <<"Scelta non consentita, scegli (s) per Si, (n) per No" <<endl;
						break;
				}
			}

	}
    return (*this);
}

int Menu::getOption(){
    return this->Option;
}

void Menu::ChoiceOptions(){
    this->Option = 1;
    
    
}
