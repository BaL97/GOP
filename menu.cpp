/*	Author: Davide Balestra 0000789078
 *	Date: 09-05-2018
 *	Implementation of class menu
 */

#include "menu.h"
#ifndef GOP_DEF
	#define GOP_DEF
	#include <iostream>
    #include <cstring>
#endif

using namespace std;

Menu::Menu(){
    setX('5');
    setPlayer_n(2);
    setSound(true);
    setMapLenght(63);
    setMode(false);
}


void Menu::setX(char x){
    this->x=x;
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


char Menu::getX(){
    return this->x;
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

void Menu::displayAll(){
   cout<< "MODALITA' = "<< getMode() << endl <<"LUNGHEZZA MAPPA = " << getMapLenght() << endl <<"SUONO = " <<getSound() << endl <<"NUMERO GIOCATORI = " <<  getPlayer_n() << endl;
    
}




void Menu::display(){
	cout <<"Menu" <<endl;
	cout <<" Nuova partita		(1)" <<endl;
	cout <<" Partita veloce		(2)"<<endl;
	cout <<" Opzioni		(3)" <<endl;
	cout <<endl <<"Esci dal gioco	(4)"<<endl;
}

void Menu::choice(){
    char tmp = '2' ;
	switch(this->x){
		case '1':
			//this->NewGame();
			break;
		case '2':
			//this->FastGame();
            break;
		case '3':
			this->setOptions();
			break;
		//Exit the game
		case '4':
			while ((tmp!='0')&&(tmp!='1')){
				cout <<"Sei sicuro di voler uscire da GOP?" <<endl <<"(1) Si" <<endl <<"(0) No"<<endl;
				cin >> tmp;
				switch(tmp){
					case '1':
						cout <<"Grazie per aver Giocato a GOP, alla prossima" <<endl;
						cout <<"Premere un tasto per continuare . . .";
						getchar();getchar();
						exit(1);
						break;
					case '0':
						//clear
						break;
					default:
						cout <<"Scelta non consentita, scegli (0) per Si, (1) per No" <<endl;
						break;
				}
			}
            break;
        default:
            cout << "Opzione non valida!" <<endl;
            break;
	}
}

void Menu::setOptions(){
    int c;
    while (true){
        cout << "OPZIONI" << endl << endl;
        cout << "Suoni                  (1)"<<endl;
        cout << "Lunghezza mappa        (2)"<<endl;
        cout << "Difficoltà             (3)"<<endl;
        cout << "Regole                 (4)"<<endl;
        cout << "Credits                (5)"<<endl<<endl;
        cout << "Menu Principale        (0)"<<endl<<endl;
        cin >> c;
        switch (c) {
            case 1:
                //casted from int to bool: if the value is 0 the sound will be deactivated, in all other cases the sound will be activated.
                cout << "SUONI" << endl;
                cout << "1) attiva i suoni" << endl << "0) disattiva suoni"<<endl;
                int b;
                cin >> b;
                setSound((bool)b);
                if (getSound())
                    cout << "suoni attivi" << endl;
                else cout << "suoni disattivati" << endl;
                break;
        
            case 2:
                cout << "Mappa" << endl;
                cout << "impostare lunghezza mappa."<<endl;
                cout << "ATTENZIONE! VALORE MINIMO IMPOSTABILE UGUALE A 63!"<<endl;
                int a;
                cin >> a;
                setMapLenght(a);
                cout << "Lunghezza mappa impostata a: " << getMapLenght() << " caselle."<< endl;
                break;
        
            case 3:
                //casted from int to bool: if the value is 0 the modality will be EASY, in all other cases it will be hard.
                cout << "DIFFICOLTA'" << endl;
                cout << "0) EASY " << endl << "1) HARD"<<endl;
                int c;
                cin >> c;
                setMode((bool)c);
                if (getMode())
                    cout << "HARDCORE MODE" << endl;
                else cout << "EASY MODE" << endl;
                break;
        
            case 4:
                cout << "ECCO LE REGOLE DEL GIOCO: "<< endl;        //print the rules.txt file
                break;
        
            case 5:
                cout << "ECCO GLI AUTORI: "<< endl;        //print the CREDITS.txt file
                break;
        
            case 0:
                cout<<"ECCO LE OPZIONI ATTIVE AL MOMENTO:"<<endl;
                this->displayAll();
                return;
                break;
        
            default:
                cout << "ERRARE E' UMANO, PERSEVERARE ANCHE."<<endl <<"Premere un tasto per continuare . . . ";
                getchar();getchar();
                break;
            }
        }
}

