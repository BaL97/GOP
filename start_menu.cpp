#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cstring>
#include<ctime>
#include <fstream>
#include "start_menu.h"
#include "player.h"
using namespace std;

void create_player() {
    player giocatore(nullptr);
    giocatore = player(nullptr);
    giocatore.insert_name();
    giocatore.insert_age();
}

void menu::NewGame() {
    int n_giocatori;
    cout << "Benvenuto nel gioco dell'oca pazza." << endl;
    cout << " " << endl;
    cout << "Quanti giocatori siete ? " << endl;
    cin >> n_giocatori;

    if (n_giocatori <= 1)
        cout << "Non puoi giocare da solo o con un numero negativo/nullo di persone." << endl;
    else
        for (int i = 0; i<n_giocatori; i++){
            create_player();
        }

    char quittare;
    while (quittare == 's') {
        cout << "Sei sicuro che vuoi uscire dal gioco ? ('s' o 'n')" << endl;
        cin >> quittare;
    }

}

void menu::FastGame() {


}

bool option::sound() {							            //takes a character input to handle the sounds
    char z;
    cout << "Vuoi attivare o disattivare i suoni ?" << endl;
    cout << "('a' per attivare 'd' per disattivare)" << endl;
    cin >> z;

    if (z == 'a')
        return true;						                //returns true if you want to activate the sounds
    else if (z == 'd')
        return false;						                //returns false if you want to disable the sounds
    else if ((z != 'a') || (z != 'd')) {
        cout << "Errore ! 'a' per attivare 'd' per disattivare" << endl;
        cout << "I suoni saranno disattivati." << endl;		//The entered character does not correspond to the choices
        return false;						                //Returns false, the sounds will be deactivated
    }

}

int option::map_lenght() {					               	//It takes an input to handle the map
    char z;
    int lenght=0;
    int conta=0;
    cout << "Qui puoi gestire la mappa, scegliere la sua lunghezza (min 63; max 90)." << endl;
    cout << "Oppure scegliere se la mappa sara creata casualmente da gioco." << endl;
    cout << "Vuoi scegliere la lunghezza o crearla casualmente ?"<< endl;
    cout << "('s' per scegliere 'c' per casuale)" << endl;
    cin >> z;

    if ( z == 's'){
        while (conta <= 3) {
            cout << "Bene. Quanto vuoi lunga la mappa ? Min 63, max 90 : " << endl;
            cin >> lenght;                                   //The user chooses the length

            if ((lenght < 63) || (lenght > 90)) {
                cout << "Errore ! Puoi scegliere da un minimo di 63 a un massimo di 90. " << endl;
                conta ++;
            }
            else return lenght;
        }
    }
    else if ( z == 'c')	lenght = (rand() % 28) + 63;		//The length is created randomly

    else if ((z != 's') || (z != 'c') || (conta >= 3))	{
        cout << "Errore !" << endl;
        cout << "La mappa sarà creata casualmente" << endl;	//The entered character does not correspond to the choices
        lenght = (rand() % 28) + 63;				        //The length is created randomly
    }

    if (conta >= 3){
        cout << "La mappa sarà creata casualmente" << endl;	//The entered character does not correspond to the choices
        lenght = (rand() % 28) + 63;				        //The length is created randomly
    }

    return lenght;							                //returns the length of the map
}

char option::level() {					            		//Function that returns a character for the choice of difficulty
    char z;
    int conta = 0;
    while (conta <= 3) {
        cout << "Le difficoltà del gioco possono essere 2." << endl;
        cout << "Modalità classica." << endl;
        cout << "Modalità anvanzata." << endl;
        cout << "Digita 'c' per la modalità classica 'a' per la modalità avanzata." << endl;
        cin >> z;

        if ((z != 'c') && (z != 'a')) {				    	//If you make a mistake for 'conta' times the entry will be set to the classic mode
            cout << "Errore ! Il carrattere inserito non corrisponde. Per favore riprova." << endl;
            conta++;
        }
        else return z;
    }

    if (conta >= 3) {
        cout << "Errore ! Verrà selezionata la modalità classica." << endl;
        z =  'c';
    }
    //The function will return a character
    return z;						                    	//c for classic a for advanced
}

void option::credits() {						            //Function that makes credits read on screen
    char z;

    ifstream credits_file;
    credits_file.open("CREDITS.txt", ios::in);			    //CREDITS.txt open for read

    cin >> z;
    if (!credits_file)
        cout << "Ops ! Qualcosa è andato storto." << endl;	//If the file does not exist
    if ((z == 'q') || (z == 'e') || (z == 'c') || (z == 'x') || (z == 's'))
        credits_file.close();					            //If the user types a character the file closes

    credits_file.clear();					               	//The error flags are reset
}

void option::rules() {					            		//Function that makes the rules read on screen
    char z;

    ifstream rules_file;
    rules_file.open("RULES.txt", ios::in);	    			//RULES.txt open for read

    cin >> z;
    if (!rules_file)
        cout << "Ops ! Qualcosa è andato storto." << endl;	//If the file does not exist
    if ((z == 'q') || (z == 'e') || (z == 'c') || (z == 'x') || (z == 's'))
        rules_file.close();					                //If the user types a character the file closes

    rules_file.clear();
}

bool option::exit() {					               		//Function that makes the user choose whether to exit the options
    char z;
    int conta = 0;
    while (conta <= 3) {
        cout << "Vuoi Tornare al menù ?" << endl;
        cout << "'s' Per uscire." << endl;
        cout << "'n' Per tornare alle opzioni." << endl;
        cout << "Cosa desideri fare ?" << endl;
        cin >> z;

        if (z=='s')
            return true;                                                                //Return true to close

        if (z == 'n')
            return false;                                                               //Return false to keep open

        if ((z != 's') && (z != 'n') ) {				    	//If you are wrong for 'conta' times to enter the game closes
            cout << "Errore ! Il carrattere inserito non corrisponde. Per favore riprova." << endl;
            conta++;
        }
    }

    if (conta >= 3) {
        cout << "Tornerai al menù principale." << endl;
        return true;                                                                   //Return false to keep open
    }
}
