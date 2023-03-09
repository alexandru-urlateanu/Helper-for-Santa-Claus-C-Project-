#include "CopilNeastamparat.h"

#include <iostream>

using namespace std;

CopilNeastamparat::CopilNeastamparat(const string &_nume, const string &_prenume, const string &_adresa,
                           unsigned int _varsta, unsigned int _numarFapteBune, const vector<shared_ptr<Jucarie>> &_jucarii,
                           int _numarCarbuni) : Copil(_nume, _prenume, _adresa, _varsta, _numarFapteBune, _jucarii) {
    this->numarCarbuni = _numarCarbuni;
}

void CopilNeastamparat::read(istream &in) {
    Copil::read(in);
    cout << "Numar carbuni: ";
    in >> numarCarbuni;
}

void CopilNeastamparat::print(ostream &out) const {
    Copil::print(out);
    out << "Numar carbuni: " << numarCarbuni << "\n";
}