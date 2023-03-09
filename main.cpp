#include "Meniu.h"
#include <iostream>
using namespace std;

void run() {
    int option = 0;
    Meniu *meniu = Meniu::getInstance();
    do {
        meniu->meniu();
        cout << "\nIntroduceti numarul optiunii: ";
        cin >> option;

        switch(option) {
            case 1: {
                meniu->adaugareCopii();
                break;
            }
            case 2: {
                meniu->afisareCopii();
                break;
            }
            case 3: {
                string numeCopil;
                cout << "Numele copilului cautat este: ";
                cin >> numeCopil;
                meniu->cautaCopil(numeCopil);
                break;
            }
            case 4: {
                meniu->ordonareVarsta();
                break;
            }
            case 5: {
                meniu->ordonareFapteBune();
                break;
            }
            case 6: {
                int id, numarFapteBune;
                cout << "ID-ul copilui este: ";
                cin >> id;
                cout << "Numarul de fapte bune adaugate: ";
                cin >> numarFapteBune;
                meniu->adaugareFapteBune(id, numarFapteBune);
            }
            case 7: {
                meniu->raportJucarii();
            }
            case 0: {
                cout << "Iesire din aplicatie\n";
                break;
            }
            default: {
                cout << "Optiunea nu exista!\n";
            }
        }
    } while (option != 0);
}

int main() {
    run();
    return 0;
}