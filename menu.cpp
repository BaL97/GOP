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

Menu::Menu(){
    setPlayer_n(2);
    setSound(true);
    setMapLenght(63);
    setMode(false);
}


void Menu::setPlayer_n(int n){
    this->Player_n = n;
}
void Menu::setSound(bool n){
    this->Sound = n;
}
void Menu::setMapLenght(int n){
    if(n<63) n=63;          //if the user set a unapceted value the lenght will be setted to a default value of 63 cells
    this->Map_l=n;
}
void Menu::setMode(bool n){
    this->Mode=n;
}



int Menu::getPlayer_n(){
    return Player_n;
}
bool Menu::getSound(){
    return Sound;
}
int Menu::getMapLenght(){
    return Map_l;
}
bool Menu::getMode(){
    return Mode;
}
void displayAll(){
    cout<< "MODALITA' = "<< getMode() << endl <<"LUNGHEZZA MAPPA = " << getMapLenght() << endl <<"SUONO = " << getSound() << endl <<"NUMERO GIOCATORI = " getPlayer_n() << endl;
}




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

void Menu::choice(char x){
	switch(x){
		case 'n':
			//this->NewGame();
			break;
		case 'v':
			//this->FastGame();
			break;
		case 'o':
			this->setOptions();
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

void Menu::setOptions(){
    cout << "OPZIONI" << endl << endl;
    cout << "Suoni                  (s)"<<endl;
    cout << "Lunghezza mappa        (m)"<<endl;
    cout << "Difficoltà             (d)"<<endl;
    cout << "Regole                 (r)"<<endl;
    cout << "Credits                (c)"<<endl<<endl;
    cout << "Menu Principale        (e)"<<endl<<endl;
    
    char c;
    cin >> c;
    while (true){
        switch (c) {
            case 's':
                cout << "SUONI" << endl;
                cout << "1) attiva i suoni" << endl << "0) disattiva suoni"<<endl;
                bool b;
                cin >> b;
                setSound(b);
                if (getSound())
                    cout << "suoni attivi" << endl;
                else cout << "suoni disattivati" << endl;
                break;
        
            case 'm':
                cout << "Mappa" << endl;
                cout << "impostare lunghezza mappa."<<endl;
                cout << "ATTENZIONE! VALORE MINIMO IMPOSTABILE UGUALE A 63!"
                int b;
                cin >> b;
                setMapLenght(b);
                cout << "Lunghezza mappa impostata a: " << getMapLenght() << " caselle."<< endl;
                break;
        
            case 'd':
                cout << "DIFFICOLTA'" << endl;
                cout << "0) EASY " << endl << "1) HARD"<<endl;
                bool b;
                cin >> b;
                setMode(b);
                if (getMode())
                    cout << "HARDCORE MODE" << endl;
                else cout << "EASY MODE" << endl;
                break;
        
            case 'r':
                cout << "ECCO LE REGOLE DEL GIOCO: "<< endl;        //print the rules.txt file
                break;
        
            case 'c':
                cout << "ECCO GLI AUTORI: "<< endl;        //print the CREDITS.txt file
                break;
        
            case 'e':
                cout<<"ECCO LE OPZIONI ATTIVE AL MOMENTO:"<<endl;
                this->displayAll();
                this->choice(this->display());
                break;
        
            default:
                cout << "ERRARE E' UMANO, PERSEVERARE ANCHE."<<endl;
                break;
            }
        }
}

