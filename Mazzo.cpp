//
// Created by Andrea D'Arpa on 02/05/18.
//

#include "Mazzo.h"
/*int Mazzo::getSegnalino(){
    return segnalino;
}

int Mazzo::setSegnalino(int i ){
    segnalino = i;
    return segnalino;
}

int Mazzo::addSegnalino(){
    return segnalino++;

}*/
 Mazzo::Mazzo() {             //genera il mazzo di carte ordinato.
    segnalino=0;

        for (int i=0; i<10; i++){
            CartaMazzoEasy[i] = new Carta_vuota;
        }
        for (int i=10; i<20; i++){
            CartaMazzoEasy[i] = new Carta_Avanti;
        }
        for (int i=20; i<25; i++){
            CartaMazzoEasy[i]= new Carta_Turno;
        }
    for (int i=25; i<30; i++) {
        CartaMazzoEasy[i] = new Carta_Tira_Avanti;
    }

    for (int i=30; i<35; i++){
        CartaMazzoEasy[i]= new Carta_Tira_Indietro;
    }
    for (int i=35; i<40; i++){
        CartaMazzoEasy[i]= new Carta_Start;
    }

}

void Mazzo::Mischia(){
    int i;
    i = 40;
    Carte *tmp;
    srand(time(nullptr));
    for (int p=0; p<40; p++){       //algoritmo che "mischia" le carte, generando un intero random che indicherà la posizione
        int k;                      //da scambiare con l'ultimo elemento della lista, che andrà poi a scalare perchè già "scambiato"
        k = rand() % i;
            tmp = CartaMazzoEasy[k];
            CartaMazzoEasy[k] = CartaMazzoEasy[i-1];
            CartaMazzoEasy[i] = tmp;
        i--;                        //decremento dell' indice dell'ultima posizione
    }
}



Carte Mazzo::Pesca(){
    segnalino ++;                          //contatore che tiene conto della carta pescata e della prossima carta da pescare
    return *CartaMazzoEasy[segnalino - 1];
}

void Mazzo::stampa(){
    int k=1;                            //funzione temporanea per il test!!!!DA ELIMINARE!!!
    for (auto &i : CartaMazzoEasy) { cout << i->getName() << k << endl ; k++;}
}

mazzetto::mazzetto(){
    segnalino=0;

    for (int i=0; i<20; i++){
        CartaMazzoHard[i] = new Carta_vuota;
    }
    for (int i=20; i<40; i++){
        CartaMazzoHard[i] = new Carta_Avanti;
    }
    for (int i=40; i<50; i++){
        CartaMazzoHard[i]= new Carta_Turno;
    }
    for (int i=50; i<55; i++) {
        CartaMazzoHard[i] = new Carta_Tira_Avanti;
    }

    for (int i=55; i<65; i++){
        CartaMazzoHard[i]= new Carta_Tira_Indietro;
    }
    for (int i=55; i<80; i++){
        CartaMazzoHard[i]= new Carta_Start;
    }
}

void mazzetto::Stampetta() {
    int k=1;                            //funzione temporanea per il test!!!!DA ELIMINARE!!!
    for (auto &i : CartaMazzoHard) { cout << i->getName() << k << endl ; k++;}
}

void mazzetto::Mischietta() {
    int i;
    i = 80;
    Carte *tmp;
    srand(time(nullptr));
    for (int p=0; p<40; p++){       //algoritmo che "mischia" le carte, generando un intero random che indicherà la posizione
        int k;                      //da scambiare con l'ultimo elemento della lista, che andrà poi a scalare perchè già "scambiato"
        k = rand() % i;
        tmp = CartaMazzoHard[k];
        CartaMazzoHard[k] = CartaMazzoHard[i-1];
        CartaMazzoHard[i] = tmp;
        i--;                        //decremento dell' indice dell'ultima posizione
    }
};

