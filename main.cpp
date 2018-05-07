#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Mazzo.h"
#include "Carte.h"

using namespace std ;

int main() {
    int x;
    cout << "inserire difficoltà mazzo: 0->facile; 1->difficile" << endl;
    char b;
    cin >> x;
    if (x==0){
        Mazzo m;
    m = Mazzo();
    m.stampa();
        cout << "vuoi mischiare il mazzo?" << endl;
        cin >> b;
        if (b=='s') {
            m.Mischia();
            m.stampa();
        } else { cout << "Fin" ;}
    }

    else {
        mazzetto m;
        m = mazzetto();
        m.Stampetta();
        cout << "vuoi mischiare il mazzo?" << endl;
        cin >> b;
        if (b=='s') {
            m.Mischietta();
            m.Stampetta();
        } else {cout << "Fin";}
    }


    return 0;
}