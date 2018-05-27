//
// Created by Andrea D'Arpa on 02/05/18.
//

#ifndef GOP_MAZZO_H
#define GOP_MAZZO_H

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "Carte.h"


class Mazzo{
private:
    Carte *CartaMazzoEasy[40];    	//vettore di puntatori a carte che fanno parte del mazzo
    int segnalino; 	//contatore alla carta corrente da pescare 
public:
    Mazzo(); //costruttore di default

    //getters & setters
    int setSegnalino(int i); 
    int getSegnalino();
   
//funzioni di gestione del mazzo

/*Mischia --> Genera un intero casuale (1-n), avviene uno swap tra la carta n e la carta k,
              se coincidono, viene rigenerato un nuovo numero casuale, n viene decrementato ad ogni iterazione */
    void Mischia();
    Carte Pesca();	//ritorna la prima carta al top del mazzo
    void stampa();
};
#endif //GOP_MAZZO_H
