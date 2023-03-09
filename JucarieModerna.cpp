#include "JucarieModerna.h"

#include <iostream>

using namespace std;

JucarieModerna::JucarieModerna(const string &_denumire, float _dimensiune, const string &_tip,
                               const string &_brand, const string &_model)
                               : Jucarie(_denumire, _dimensiune, _tip),
                               JucarieEducativa(_denumire, _dimensiune, _tip, "generala"),
                               JucarieElectronica(_denumire, _dimensiune, _tip, 1) {
    this->brand = _brand;
    this->model = _model;
}

void JucarieModerna::read(istream &in) {
    cout << "Denumire: ";
    in >> denumire;

    cout << "Dimensiune: ";
    in >> dimensiune;

    cout << "Tip: ";
    in >> tip;

    cout << "Brand: ";
    in >> brand;

    cout << "Model: ";
    in >> model;
}

void JucarieModerna::print(ostream &out) const {
    JucarieEducativa::print(out);
    out << "Numar baterii: " << numarBaterii << "\n";
    out << "Brand: " << brand << "\n";
    out << "Model: " << model << "\n";
}