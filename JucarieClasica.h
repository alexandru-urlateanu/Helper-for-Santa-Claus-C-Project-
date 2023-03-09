#ifndef PROIECT_03_JUCARIECLASICA_H
#define PROIECT_03_JUCARIECLASICA_H

#include "Jucarie.h"

#include <iostream>

using namespace std;

class JucarieClasica : public Jucarie {
private:
    string material;
    string culoare;

public:
    JucarieClasica() = default;
    ~JucarieClasica() override = default;
    JucarieClasica(const string &_denumire, float _dimensiune, const string &_tip,
                   const string &_material, const string &_culoare);
    JucarieClasica(const JucarieClasica&) = default;
    JucarieClasica & operator=(const JucarieClasica&) = default;

    void read(istream& in) override;
    void print(ostream& out) const override;
};


#endif //PROIECT_03_JUCARIECLASICA_H