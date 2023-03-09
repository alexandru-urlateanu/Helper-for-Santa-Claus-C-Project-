#ifndef PROIECT_03_JUCARIEELECTRONICA_H
#define PROIECT_03_JUCARIEELECTRONICA_H

#include "Jucarie.h"

#include <iostream>

using namespace std;

class JucarieElectronica : virtual public Jucarie {
protected:
    int numarBaterii{};

public:
    JucarieElectronica() = default;
    ~JucarieElectronica() override = default;
    JucarieElectronica(const string &_denumire, float _dimensiune, const string &_tip, int _numarBaterii);
    JucarieElectronica(const JucarieElectronica&) = default;
    JucarieElectronica & operator=(const JucarieElectronica&) = default;

    void read(istream& in) override;
    void print(ostream& out) const override;
};


#endif //PROIECT_03_JUCARIEELECTRONICA_H