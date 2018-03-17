#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cstring>
#include "carte.h"
using namespace std;



//there'll be 6 type of cards that will be initialized in Main calling the constructor.

Carta_vuota::Carta_vuota(string N ="carta vuota", string D="non fa nulla", int I=1){
        strcpy(Name, N);
        strcpy(Description, D);
        Id=I;
    }
void Carta_vuota::message() {            //messaggio che stampa la descrizione della carta su terminale
        cout << Carta_vuota.Name << " " << Carta_vuota.Description;
    }
Carta_Avanti::Carta_Avanti(string N="AVANTI TUTTA!", string D="avanti di 1", int I=2){
        strcpy(Name, N);
        strcpy(Description, D);
        Id=I;
    }
void Carta_Avanti::message() {            //messaggio che stampa la descrizione della carta su terminale
        cout << Carta_Avanti.Name<< " " << Carta_Avanti.Description << endl;
    }
void Carta_Avanti::evento (personaggio P){                //funzione ipotetica per spostare in avanti il personaggio. La gestione sarà determinata dalla classe personaggio.
        P.move();
    }
Carta_Turno::Carta_Turno(string N="BLOCCATO", string D="ops, sei bloccato per un turno...", int I=3){
        strcpy(Name, N);
        strcpy(Description, D);
        Id=I;
    }
void Carta_Turno::message(){
                    cout<< Carta_Turno.Name << " " << Carta_Turno.Description<<endl;
                }
void Carta_Turno::evento(personaggio P){
                    P.turno = false //ipotizzando che la gestione del turno venga esguita tramite un Booleano TRUE quando può muoversi e FALSE quando no
                }

Carta_Tira_Avanti::Carta_Tira_Avanti(string N="TIRA ANCORA!", string D="e vai avanti", int I=4){
        strcpy(Name, N);
        strcpy(Description, D);
        Id=I;
    }
void Carta_Tira_Avanti::message() {            //messaggio che stampa la descrizione della carta su terminale
        cout << Carta_Tira_Avanti.Name<< " " << Carta_Tira_Avanti.Description << endl;
    }
void Carta_Tira_Avanti::evento(personaggio P, dado D){
        int n = d.tiraDado();       //funzione ipotetica di lancio del dado
        while (n>0){
            P.move();
            n-- ;
        }
    }

Carta_Tira_Indietro::Carta_Tira_Indietro(string N="TIRA ANCORA!", string D="e vai indietro", int I=5){
        strcpy(Name, N);
        strcpy(Description, D);
        Id=I;
    }
void Carta_Tira_Indietro::message() {            //messaggio che stampa la descrizione della carta su terminale
        cout << Carta_Tira_Indietro.Name<< " " << Carta_Tira_Indietro.Description << endl;
    }
void Carta_Tira_Indietro::evento(personaggio P, dado D){
        int n = d.tiraDado();       //funzione ipotetica di lancio del dado
        while (n>0){
            P.moveBack();
            n-- ;
        }
    }

Carta_Start::Carta_Start(string N="TANTO VA LA GATTA AL LARDO...", string D="(che) Torna al punto di partenza", int I=5){
        strcpy(Name, N);
        strcpy(Description, D);
        Id=I;
    }
void Carta_Start::message() {            //messaggio che stampa la descrizione della carta su terminale
        cout << Carta_Start.Name<< " " << Carta_Start.Description << endl;
    }
