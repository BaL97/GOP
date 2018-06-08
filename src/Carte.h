//
// Created by Andrea D'Arpa on 02/05/18.
//

#ifndef GOP_CARTE_H
#define GOP_CARTE_H


#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Carte{
protected:
    string Name;
    string Description;
    int Id;
public:
    string getName();
    string getDescription();
    int getId();
    void setName(string Name);
    void setDescription(string Description);
    void setId(int id);
    void messaggio();
};

class Carta_vuota:public Carte{
public:
    Carta_vuota();
};

class Carta_Avanti:public Carte{
public:
    Carta_Avanti();
};

class Carta_Turno:public Carte{
public:
    Carta_Turno();
};

class Carta_Tira_Avanti:public Carte{
public:
    Carta_Tira_Avanti();
};

class Carta_Tira_Indietro:public Carte{
public:
    Carta_Tira_Indietro();
  };

class Carta_Start:public Carte{
public:
    Carta_Start();
};
#endif //GOP_CARTE_H
