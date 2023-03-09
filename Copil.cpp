#include "Copil.h"
#include "JucarieClasica.h"
#include "JucarieEducativa.h"
#include "JucarieElectronica.h"
#include "JucarieModerna.h"

#include <limits>
#include <iostream>

using namespace std;

int Copil::static_idCopil = 0;

Copil::Copil() : idCopil(++static_idCopil) {}

Copil::Copil(const string &_nume, const string &_prenume, const string &_adresa, unsigned int _varsta,
             unsigned int _numarFapteBune, const vector<shared_ptr<Jucarie>> &_jucarii) : idCopil(++static_idCopil) {
    this->nume = _nume;
    this->prenume = _prenume;
    this->adresa = _adresa;
    this->varsta = _varsta;
    this->numarFapteBune = _numarFapteBune;
    this->jucarii = _jucarii;
}

void Copil::read(istream &in) {
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

void Copil::print(ostream &out) const {
    out << "ID: " << idCopil << "\n";
    out << "Nume si Prenume: " << nume << " " << prenume << "\n";
    out << "Adresa: " << adresa << "\n";
    out << "Varsta: " << varsta << "\n";
    out << "Numar fapte bune: " << numarFapteBune << "\n";
    out << "Jucarii:\n";
    for (auto &jucarie : jucarii) {
        jucarie->print(out);
    }
}

istream &operator>>(istream &in, Copil &copil) {
    copil.read(in);
    return in;
}

ostream &operator<<(ostream &out, const Copil &copil) {
    copil.print(out);
    return out;
}

const string &Copil::getNume() const {
    return nume;
}

unsigned int Copil::getVarsta() const {
    return varsta;
}

unsigned int Copil::getNumarFapteBune() const {
    return numarFapteBune;
}

const int Copil::getIdCopil() const {
    return idCopil;
}

void Copil::setNumarFapteBune(unsigned int numarFapteBune) {
    Copil::numarFapteBune = numarFapteBune;
}

void Copil::setJucarii(const vector<shared_ptr<Jucarie>> &jucarii) {
    Copil::jucarii = jucarii;
}

const vector<shared_ptr<Jucarie>> &Copil::getJucarii() const {
    return jucarii;
}