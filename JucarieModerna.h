#ifndef PROIECT_03_JUCARIEMODERNA_H
#define PROIECT_03_JUCARIEMODERNA_H

#include "JucarieEducativa.h"
#include "JucarieElectronica.h"

#include <iostream>

using namespace std;

class JucarieModerna : public JucarieEducativa, public JucarieElectronica {
private:
    string brand;
    string model;

public:
    JucarieModerna() = default;
    ~JucarieModerna() override = default;
    JucarieModerna(const string &_denumire, float _dimensiune, const string &_tip, const string &_brand,
                   const string &_model);
    JucarieModerna(const JucarieModerna&) = default;
    JucarieModerna &operator=(const JucarieModerna&) = default;

    void read(istream &in) override;
    void print(ostream &out) const override;
};


#endif //PROIECT_03_JUCARIEMODERNA_H