/*	BOX.H
*	AUTHORS:
*		Andrea D'Arpa
*		Davide Balestra
*
*	DESCRIPTION:
*		Header file of Box's class.
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include "Mazzo.h"

using namespace std;

class Box{
protected:
	string name;						//nome della casella
	string description;					//descrizione del tipo di casella
	int id;							//intero che identifica il tipo di casella
	
public:
	//Player *p;						//Puntatore alla lista di trabocco dei pg
	Box *prev;						//parametri next prev per la gestione del cammino dei pg sulla mappa
	Box *next;
	Carte *c;						//puntatore alla carta da pescare
	
//constructors
	Box();							//default constructor
	Box(string n, string d, int id);			//costruttore con parametri
	
	void action();						//interfaccia del metodo che verrà implementato nelle sottoclassi

//SETTER METHODS
	void setName(string n);
	void setDes(string n);
	void setId(int n);

//GETTER METHODS
	string getName();
	string getDes();
	int getId();
};

class Start : public Box{
	public:
		Start();
};

class End : public Box{
	End();
};

class Draw : public Box{
	Draw();
};

class Bridge : public Box{
	Bridge();
};

class Prison : public Box{
	Prison();
};

class Inn : public Box{
	Inn();
};

class Labirinth : public Box{
	Labirinth();
};

class Skull : public Box{
	Skull();
};
