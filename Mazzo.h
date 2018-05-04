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
    Carte *CartaMazzoEasy[40];
public:
    int segnalino;
    int setSegnalino(int i); //segnalino per scorrere l'array
    int getSegnalino();
    int addSegnalino();
    Mazzo(); //costruttore
    void Mischia(); //mischia gli ogetti all'interno dell'array di carte
    Carte Pesca(); //Funz Pescaggio
    void stampa();
    void setDiff(int HRD);

};

class mazzetto:public Mazzo{
private:
    Carte *CartaMazzoHard[80];
public:
    mazzetto();
    void Stampetta();
    void Mischietta();
};



#endif //GOP_MAZZO_H
