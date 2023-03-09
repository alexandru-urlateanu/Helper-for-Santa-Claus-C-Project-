#include "JucarieElectronica.h"

#include <iostream>

using namespace std;

JucarieElectronica::JucarieElectronica(const string &_denumire, float _dimensiune, const string &_tip,
                                       int _numarBaterii) : Jucarie(_denumire, _dimensiune, _tip) {
    this->numarBaterii = _numarBaterii;
}

void JucarieElectronica::read(istream &in) {
    Jucarie::read(in);

    cout << "Numar baterii: ";
    in >> numarBaterii;
}

void JucarieElectronica::print(ostream &out) const {
    Jucarie::print(out);
    out << "Numar baterii: " << numarBaterii << "\n";
}