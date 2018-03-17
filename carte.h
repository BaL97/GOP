#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cstring>

class Carte{
private:
    string Name;
    string Description;
    int Id;
    
};
class Carta_vuota:public Carte{
public:
    Carta_vuota(string N ="carta vuota", string D="non fa nulla", int I=1);
    void message();
};
class Carta_Avanti:public Carte{
public:
    Carta_Avanti(string N="AVANTI TUTTA!", string D="avanti di 1", int I=2);
    void message();            //messaggio che stampa la descrizione della carta su terminale
    void evento (personaggio P)                //funzione ipotetica per spostare in avanti il personaggio. La gestione sarà determinata dalla classe personaggio.
};
class Carta_Turno:public Carte{
public:
    Carta_Turno(string N="BLOCCATO", string D="ops, sei bloccato per un turno...", int I=3);
    void message();
    
    void evento(personaggio P);//ipotizzando che la gestione del turno venga esguita tramite un Booleano TRUE quando può muoversi e FALSE quando no
    
};



class Carta_Tira_Avanti:public Carte{
public:
    Carta_Tira_Avanti(string N="TIRA ANCORA!", string D="e vai avanti", int I=4);
    void message();            //messaggio che stampa la descrizione della carta su terminale
    
    void evento(personaggio P, dado D);
    
    
};

class Carta_Tira_Indietro:public Carte{
public:
    Carta_Tira_Indietro(string N="TIRA ANCORA!", string D="e vai indietro", int I=5);
    void message();            //messaggio che stampa la descrizione della carta su terminale
    
    void evento(personaggio P, dado D);
    
};

class Carta_Start:public Carte{
public:
    Carta_Start(string N="TANTO VA LA GATTA AL LARDO...", string D="(che) Torna al punto di partenza", int I=5);
    void message();
};

