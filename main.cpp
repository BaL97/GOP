#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Mazzo.h"
#include "Carte.h"

using namespace std;

int main() {
    int x;
    cout << "inserire difficoltà mazzo: 0->facile; 1->difficile" << endl;
    cin >> x;
    if (x==0){
        Mazzo m;
    m = Mazzo();
    m.stampa();
        cout<<endl;
        m.Mischia();
        m.stampa();
    }

    else {
        mazzetto m;
        m = mazzetto();
        m.Stampetta();
        cout<<endl;
        m.Mischietta();
        m.Stampetta();
    }


    return 0;
}