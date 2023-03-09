#include "Jucarie.h"

#include <iostream>

using namespace  std;

Jucarie::Jucarie(const string &_denumire, float _dimensiune, const string &_tip) {
    this->denumire = _denumire;
    this->dimensiune = _dimensiune;
    this->tip = _tip;
}

istream &operator>>(istream &in, Jucarie &jucarie) {
    jucarie.read(in);
    return in;
}

ostream &operator<<(ostream &out, const Jucarie &jucarie) {
    jucarie.print(out);
    return out;
}

void Jucarie::read(istream &in) {
    cout << "Denumire: ";
    in >> denumire;

    cout << "Dimensiune: ";
    in >> dimensiune;

    cout << "Tip: ";
    in >> tip;
}

void Jucarie::print(ostream &out) const {
    out << "Denumire: " << denumire << "\n";
    out << "Dimensiune: " << dimensiune << "\n";
    out << "Tip: " << tip << "\n";
}