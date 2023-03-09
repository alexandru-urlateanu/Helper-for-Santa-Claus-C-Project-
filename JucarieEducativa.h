#ifndef PROIECT_03_JUCARIEEDUCATIVA_H
#define PROIECT_03_JUCARIEEDUCATIVA_H

#include "Jucarie.h"

#include <iostream>

using namespace std;

class JucarieEducativa : virtual public Jucarie {
protected:
    string abilitate;

public:
    JucarieEducativa() = default;
    ~JucarieEducativa() override = default;
    JucarieEducativa(const string &_denumire, float _dimensiune, const string &_tip, const string &_abilitate);
    JucarieEducativa(const JucarieEducativa&) = default;
    JucarieEducativa & operator=(const JucarieEducativa&) = default;

    void read (istream& in) override;
    void print(ostream& out) const override;
};


#endif //PROIECT_03_JUCARIEEDUCATIVA_H