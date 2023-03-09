#include "Meniu.h"
#include "CopilCuminte.h"
#include "CopilNeastamparat.h"
#include "JucarieClasica.h"
#include "JucarieEducativa.h"
#include "JucarieElectronica.h"
#include "JucarieModerna.h"
#include <iostream>
#include <algorithm>

using namespace std;

Meniu* Meniu::instance = nullptr;

Meniu *Meniu::getInstance() {
    if (instance == nullptr) {
        instance = new Meniu();
    }
    return instance;
}

void Meniu::meniu() {
    cout << "\n\tMENIU\tALEGETI O OPTIUNE:\n";
    cout << "1. Citire Copii\n";
    cout << "2. Afisare Copii\n";
    cout << "3. Cautare Copil\n";
    cout << "0. Iesire\n";
}

void Meniu::adaugareCopii() {
    unsigned int numarCopii;
    cout << "Numarul de copii este: ";
    cin >> numarCopii;

    for (int i = 0 ; i < numarCopii ; i++) {
        unsigned int option, conditieCitire = 0;
        shared_ptr<Copil> tempCopil;
        while (conditieCitire == 0) {
            cout << "Tip copil (1-Cuminte, 2-Neastamparat): ";
            cin >> option;
            conditieCitire = 1;
            try {
                switch (option) {
                    case 1: {
                        tempCopil = make_shared<CopilCuminte>();
                        break;
                    }
                    case 2: {
                        tempCopil = make_shared<CopilNeastamparat>();
                        break;
                    }
                    default: {
                        throw option;
                    }
                }
                tempCopil->read(cin);
                copii.push_back(tempCopil);
            } catch(...) {
                cout << "Eroare: Optiune invalida!\n";
                conditieCitire = 0;
            }
        }
    }
}

void Meniu::afisareCopii() {
    for (auto &copil : copii) {
        copil->print(cout);
    }
}

void Meniu::cautaCopil(const string &numeCopil) {
    size_t found;
    for (auto &copil : copii) {
        found = copil->getNume().find(numeCopil);
        if (found != string::npos) {
            copil->print(cout);
        }
    }
}

void Meniu::ordonareVarsta() {
    sort(copii.begin(), copii.end(), [](const shared_ptr<Copil>& a, const shared_ptr<Copil>& b) -> bool {
        return a->getVarsta() > b->getVarsta();
    });
    afisareCopii();
}

void Meniu::ordonareFapteBune() {
    sort(copii.begin(), copii.end(), [](const shared_ptr<Copil>& a, const shared_ptr<Copil>& b) -> bool {
        return a->getNumarFapteBune() < b->getNumarFapteBune();
    });
    afisareCopii();
}

void Meniu::adaugareFapteBune(int idCopil, int numarFapteBune) {
    for (auto &copil : copii) {
        if (copil->getIdCopil() == idCopil) {
            copil->setNumarFapteBune(copil->getNumarFapteBune() + numarFapteBune);
            vector<shared_ptr<Jucarie>> jucarii = copil->getJucarii();
            for (int i = 0 ; i < numarFapteBune ; i++) {
                shared_ptr<Jucarie> tempJucarie;
                unsigned int option, conditieCitire = 0;
                while (conditieCitire == 0) {
                    cout << "Tip jucarie (1-clasica, 2-educativa, 3-electronica, 4-moderna): ";
                    cin >> option;
                    conditieCitire = 1;
                    try {
                        if (option < 1 || option > 4) {
                            throw option;
                        }
                        switch (option) {
                            case 1: {
                                tempJucarie = make_shared<JucarieClasica>();
                                break;
                            }
                            case 2: {
                                tempJucarie = make_shared<JucarieEducativa>();
                                break;
                            }
                            case 3: {
                                tempJucarie = make_shared<JucarieElectronica>();
                                break;
                            }
                            case 4: {
                                tempJucarie = make_shared<JucarieModerna>();
                                break;
                            }
                        }
                        tempJucarie->read(cin);
                        jucarii.push_back(tempJucarie);
                    } catch (...) {
                        cout << "Eroare: Optiune invalida!\n";
                        conditieCitire = 0;
                    }
                }
            }
            copil->setJucarii(jucarii);
        }
    }
}

void Meniu::raportJucarii() {
    int numarJucarii = 0;
    int frecventaJucarii[4] = {0, 0, 0, 0};
    for (auto &copil : copii) {
        vector<shared_ptr<Jucarie>> jucarii = copil->getJucarii();
        numarJucarii += jucarii.size();
        for (auto &jucarie : jucarii) {
            if (dynamic_pointer_cast<shared_ptr<JucarieClasica>>(jucarie)) {
                frecventaJucarii[0]++;
            } else if (dynamic_pointer_cast<shared_ptr<JucarieEducativa>>(jucarie)) {
                frecventaJucarii[1]++;
            } else if (dynamic_pointer_cast<shared_ptr<JucarieElectronica>>(jucarie)) {
                frecventaJucarii[2]++;
            } else {
                frecventaJucarii[3]++;
            }
        }
    }
    cout << "Numarult totatl de jucarii este " << numarJucarii << " dintre care " << frecventaJucarii[0] << " sunt clasice, "
                << frecventaJucarii[1] << " sunt educative, " << frecventaJucarii[2] << " sunt electronice, " << frecventaJucarii[3]
                << " sunt moderne.\n";
}