#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cstring>
#include "cell.h"

class Carte{
protected:
    string Name;
    string Description;
    int Id;
    int Num;
public:
    void message(string Name, string Description);
    void getName();
    void getDescription();
    void getId();
    void setName(string Name);
    void setDescription(string Description);
    void setId(int Id);
    void evento(personaggio p);
    void eventoDado(personaggio p, dado d);
};
class Carta_vuota:public Carte{
public:
    Carta_vuota(string N ="carta vuota", string D="non fa nulla", int I=1);//10
 
};
class Carta_Avanti:public Carte{
public:
    Carta_Avanti(string N="AVANTI TUTTA!", string D="avanti di 1", int I=2);
     evento ()                //funzione ipotetica per spostare in avanti il personaggio. La gestione sarà determinata dalla classe personaggio. 10
};
class Carta_Turno:public Carte{
public:
    Carta_Turno(string N="BLOCCATO", string D="ops, sei bloccato per un turno...", int I=3);
     evento();//ipotizzando che la gestione del turno venga esguita tramite un Booleano TRUE quando può muoversi e FALSE quando no. 5
    
};



class Carta_Tira_Avanti:public Carte{
public:
    Carta_Tira_Avanti(string N="TIRA ANCORA!", string D="e vai avanti", int I=4);
    
  eventoDado();
    
    
}; //5

class Carta_Tira_Indietro:public Carte{
public:
    Carta_Tira_Indietro(string N="TIRA ANCORA!", string D="e vai indietro", int I=5);
    
     eventoDado();
    
};//5

class Carta_Start:public Carte{
public:
    Carta_Start(string N="TANTO VA LA GATTA AL LARDO...", string D="(che) Torna al punto di partenza", int I=5);
     evento();
};//5



