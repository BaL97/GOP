#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cstring>
#include "carte.h"
#include "cell.h"
using namespace std;



//there'll be 6 type of cards that will be initialized in Main calling the constructor.

void Carte::message(Name, Description){
cout<< Name << ": "<< Description << endl;
}
void Carte::setName(Nome){
    strcpy(Name,Nome);
};
void Carte::setDescription(Descrizione){
    strcpy(Description,Descrizione);
};
void Carte::setId(id){
    Id=id;
};
void Carte::getName(){
    return Name;
};
void Carte::getDescription(){
    return Description;
};
void Carte::getId(){
    return Id;
    
    void Carte::setNum(){
        
    }
    void Carte::getNum(){
        
    }
}
//cambiare i costruttori con set get method.
Carta_vuota::Carta_vuota(){
    Carta_vuota::setId();
    Carta_vuota::setName();
    Carta_vuota::setId();
    }

Carta_Avanti::Carta_Avanti(string N="AVANTI TUTTA!", string D="avanti di 1", int I=2){
        strcpy(Name, N);
        strcpy(Description, D);
        Id=I;
    }
void Carta_Avanti::evento (){
        P->move();
    }
Carta_Turno::Carta_Turno(string N="BLOCCATO", string D="ops, sei bloccato per un turno...", int I=3){
        strcpy(Name, N);
        strcpy(Description, D);
        Id=I;
    }
void Carta_Turno::evento(personaggio P){
    P->blocked(1);
                }

Carta_Tira_Avanti::Carta_Tira_Avanti(string N="TIRA ANCORA!", string D="e vai avanti", int I=4){
        strcpy(Name, N);
        strcpy(Description, D);
        Id=I;
    }
void Carta_Tira_Avanti::evento(){
        int n = d->tiraDado();
        while (n>0){
            P->move();
            n-- ;
        }
    }

Carta_Tira_Indietro::Carta_Tira_Indietro(string N="TIRA ANCORA!", string D="e vai indietro", int I=5){
        strcpy(Name, N);
        strcpy(Description, D);
        Id=I;
    }
void Carta_Tira_Indietro::evento(){
        int n = d.tiraDado();       //funzione ipotetica di lancio del dado
        while (n>0){
            P->move();
            n-- ;
        }
    }

Carta_Start::Carta_Start(string N="TANTO VA LA GATTA AL LARDO...", string D="(che) Torna al punto di partenza", int I=5){
        strcpy(Name, N);
        strcpy(Description, D);
        Id=I;
    }
Carta_Start::evento(){
    p->position=Start;
}

