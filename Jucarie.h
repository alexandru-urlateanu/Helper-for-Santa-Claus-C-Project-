#ifndef PROIECT_03_JUCARIE_H
#define PROIECT_03_JUCARIE_H

#include <iostream>

using namespace std;

class Jucarie {
protected:
    string denumire;
    float dimensiune{};
    string tip;

public:
    Jucarie() = default;
    virtual ~Jucarie() = default;
    Jucarie(const string &_denumire, float _dimensiune, const string &_tip);
    Jucarie(const Jucarie&) = default;
    Jucarie &operator=(const Jucarie&) = default;

    friend istream& operator>>(istream& in, Jucarie& jucarie);
    friend ostream& operator<<(ostream& out, const Jucarie& jucarie);

    virtual void read(istream& in);
    virtual void print(ostream& out) const;
};

#endif //PROIECT_03_JUCARIE_H