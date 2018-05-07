//
// Created by Andrea D'Arpa on 02/05/18.
//

#ifndef GOP_CARTE_H
#define GOP_CARTE_H


#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstring>
#include "player.h"
using namespace std;

class Carte{
protected:
    string Name;
    string Description;
    int Id;
    //int Num;
public:
    string getName();
    string getDescription();
    int getId();
    void setName(string Name);
    void setDescription(string Description);
    void setId(int Id);
    void messaggio();
};

class Carta_vuota:public Carte{
public:
    Carta_vuota();//10

};

class Carta_Avanti:public Carte{
public:
    Carta_Avanti();
    //evento ()                //funzione ipotetica per spostare in avanti il personaggio. La gestione sarà determinata dalla classe personaggio. 10
    void evento(ptr_player p);
};

class Carta_Turno:public Carte{
public:
    Carta_Turno();
    //evento();//ipotizzando che la gestione del turno venga esguita tramite un Booleano TRUE quando può muoversi e FALSE quando no. 5

    void evento(ptr_player p);
};

class Carta_Tira_Avanti:public Carte{
public:
    Carta_Tira_Avanti();

    //eventoDado();
    void evento(ptr_player p);
}; //5

class Carta_Tira_Indietro:public Carte{
public:
    Carta_Tira_Indietro();

    void evento(ptr_player p);
};//5

class Carta_Start:public Carte{
public:
    Carta_Start();
    void evento(ptr_player p);
};//5






#endif //GOP_CARTE_H
