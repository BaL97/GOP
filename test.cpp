#include <iostream>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include<ctime>
#include <fstream>
#include "start_menu.h"
#include "player.h"

using namespace std;


int main () {
    char x;
    option  test;
    menu    debug;
    cout << "Benvenuto nel gioco GOP." << endl;
    cout << "Gioco dell'oca Pazza." << endl;
    cout << " " << endl;

    while (x!='q') {
        cout << "Menu" << endl;
        cout << " " << endl;
        cout << "Nuova Partita      (n)" << endl;
        cout << "Partita Veloce     (v)" << endl;
        cout << "Opzioni            (o)" << endl;
        cout << " " << endl;
        cout << "Esci dal Gioco     (q)" << endl;
        cin >> x;

        switch (x) {
            case 'n':
                debug.NewGame();
                break;
            case 'v':
                debug.FastGame();
                break;
            case 'o':
                do {
                    cout << "Suoni                (s)" << endl;
                    cout << "Lunghezza Mappa      (m)" << endl;
                    cout << "Livello              (l)" << endl;
                    cout << "Crediti              (c)" << endl;
                    cout << "Regole               (r)" << endl;
                    cout << "Esci                 (e)" << endl;
                    cin >> x;


                    switch (x) {
                        case 's':
                            test.sound();
                            break;
                        case 'm':
                            test.map_lenght();
                            break;
                        case 'l':
                            test.level();
                            break;
                        case 'c':
                            test.credits();
                            break;
                        case 'r':
                            test.rules();
                            break;
                        case 'e':
                            //  test.exit();
                            break;
                    }
                } while (!test.exit());
        }
    }

    return 0;
}
