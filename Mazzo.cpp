//
// Created by Andrea D'Arpa on 02/05/18.
//

#include "Mazzo.h"
 Mazzo::Mazzo() {             //genera il mazzo di carte ordinato.
   
        for (int i=0; i<10; i++){
            CartaMazzoEasy[i] = new Carta_vuota();
        }
        for (int i=10; i<20; i++){
            CartaMazzoEasy[i] = new Carta_Avanti();
        }
        for (int i=20; i<25; i++){
            CartaMazzoEasy[i]= new Carta_Turno();
        }
    for (int i=25; i<30; i++) {
        CartaMazzoEasy[i] = new Carta_Tira_Avanti();
    }

    for (int i=30; i<35; i++){
        CartaMazzoEasy[i]= new Carta_Tira_Indietro();
    }
    for (int i=35; i<40; i++){
        CartaMazzoEasy[i]= new Carta_Start();
    }
}

void Mazzo::setSegnalino(int i){
	this->segnalino=i;
}

int Mazzo::getSegnalino(){
	return this->segnalino;
}


void Mazzo::Mischia(){
    int i;
    i = 40;
    Carte *tmp;
    for (int p=0; p<40; p++){       //algoritmo che "mischia" le carte, generando un intero random che indicherà la posizione
        int k;                      //da scambiare con l'ultimo elemento della lista, che andrà poi a scalare perchè già "scambiato"
        k = rand() % i;
            tmp = CartaMazzoEasy[k];
            CartaMazzoEasy[k] = CartaMazzoEasy[i-1];
            CartaMazzoEasy[i] = tmp;
        i--;                        //decremento dell' indice dell'ultima posizione
    }
this->setSegnalino(0);
}


Carte Mazzo::Pesca(){
	//segnalino ++;                          //contatore che tiene conto della carta pescata e della prossima carta da pescare
   	 return *CartaMazzoEasy[segnalino++];
}

void Mazzo::stampa(){
    int k=1;                            //funzione temporanea per il test!!!!DA ELIMINARE!!!
    for (auto &i : CartaMazzoEasy) { cout << i->getName() << " - "<< k <<" - " << i->getDescription() << endl ; k++;}
}
