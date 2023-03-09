#include "JucarieClasica.h"

#include <iostream>

using namespace std;

JucarieClasica::JucarieClasica(const string &_denumire, float _dimensiune, const string &_tip,
                               const string &_material, const string &_culoare)
                               : Jucarie(_denumire, _dimensiune, _tip) {
    this->material = _material;
    this->culoare = _culoare;
}

void JucarieClasica::read(istream &in) {
    Jucarie::read(in);

    cout << "Material: ";
    in >> material;

    cout << "Culoare: ";
    in >> culoare;
}

void JucarieClasica::print(ostream &out) const {
    Jucarie::print(out);
    out << "Material: " << material << "\n";
    out << "Culoare: " << culoare << "\n";
}
