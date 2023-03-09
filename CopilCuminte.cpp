#include <iostream>
#include <limits>
#include "CopilCuminte.h"
#include "JucarieClasica.h"
#include "JucarieEducativa.h"
#include "JucarieElectronica.h"
#include "JucarieModerna.h"

#include <iostream>

using namespace std;

CopilCuminte::CopilCuminte(const string &_nume, const string &_prenume, const string &_adresa,
                           unsigned int _varsta, unsigned int _numarFapteBune, const vector<shared_ptr<Jucarie>> &_jucarii,
                           int _numarDulciuri) : Copil(_nume, _prenume, _adresa, _varsta, _numarFapteBune, _jucarii) {
    this->numarDulciuri = _numarDulciuri;
}

void CopilCuminte::read(istream &in) {
    cout << "Nume: ";
    in >> nume;

    cout << "Prenume: ";
    in >> prenume;

    cout << "Adresa: ";
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(in, adresa);

    cout << "Varsta: ";
    in >> varsta;

    cout << "Numar fapte bune: ";
    in >> numarFapteBune;
    // este corect, dar pentru testare ramane comentat
//    while(numarFapteBune < 10) {
//        cout << "Numar fapte bune gresit! Numarul de fapte bune trebuie sa fie >= 10!\n";
//        cout << "Numar fapte bune: ";
//        in >> numarFapteBune;
//    }
    cout << "Numar dulciuri: ";
    in >> numarDulciuri;

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
}

void CopilCuminte::print(ostream &out) const {
    Copil::print(out);
    out << "Numar dulciuri: " << numarDulciuri << "\n";
}