// Created by Andrea D'Arpa on 02/05/18.

#include "Carte.h"

using namespace std;


//there'll be 6 type of cards that will be initialized in Main calling the constructor.

void Carte::messaggio(){
    cout<< Name << ": "<< Description << endl;
}
void Carte::setName(string Nome){
    this->Name = Nome;
};
void Carte::setDescription(string Descrizione){
    Description = Descrizione;
};
void Carte::setId(int id){
    this->Id=id;
};
string Carte::getName(){
    return Name;
};
string Carte::getDescription(){
    return Description;
};
int Carte::getId(){
    return Id;
};


Carta_vuota::Carta_vuota(){
    setId(0);
    setName("Carta Vuota");
    setDescription("E che t'aspettavi?");
}



Carta_Avanti::Carta_Avanti(){
    setName("AVANTI TUTTA!");
    setDescription("avanti di 1");
    setId(1);
}

Carta_Turno::Carta_Turno(){
    setName("Bloccato!");
    setDescription("ops, sei bloccato per un turno...");
    setId(2);
}

Carta_Tira_Avanti::Carta_Tira_Avanti(){
    setName("Tira Ancora!");
    setDescription("e vai avanti");
    setId(3);
}


Carta_Tira_Indietro::Carta_Tira_Indietro(){
    setName("Tira Ancora, MA!");
    setDescription("Questa volta vai dietro!");
    setId(4);
}

Carta_Start::Carta_Start() {
        setName("Tanto va la gatta al lardo");
          setDescription("che torna al punto di partenza!");
          setId(5);
      }
