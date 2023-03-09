#include "JucarieEducativa.h"

#include <iostream>

using namespace std;

JucarieEducativa::JucarieEducativa(const string &_denumire, float _dimensiune, const string &_tip,
                                   const string &_abilitate) :Jucarie(_denumire, _dimensiune, _tip) {
    this->abilitate = _abilitate;
}

void JucarieEducativa::read(istream &in) {
    Jucarie::read(in);

    cout << "Abilitate: ";
    in >> abilitate;
}

void JucarieEducativa::print(ostream &out) const {
    Jucarie::print(out);
    out << "Abilitate: " << abilitate << "\n";
}