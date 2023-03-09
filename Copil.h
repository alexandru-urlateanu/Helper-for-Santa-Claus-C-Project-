#ifndef PROIECT_03_COPIL_H
#define PROIECT_03_COPIL_H

#include <iostream>
#include <memory>
#include <vector>
#include "Jucarie.h"



using namespace std;

class Copil {
protected:
    static int static_idCopil;
    const int idCopil{};
    string nume;
    string prenume;
    string adresa;
    unsigned int varsta{};
    unsigned int numarFapteBune{};
    vector<shared_ptr<Jucarie>> jucarii; // echivalent cu: vector<Jucarie*> jucarii;
public:
    Copil();
    virtual ~Copil() = default;
    Copil(const string& _nume, const string &_prenume, const string &_adresa, unsigned int _varsta,
          unsigned int _numarFapteBune, const vector<shared_ptr<Jucarie>>& _jucarii);
    Copil(const Copil&) = default;
    Copil &operator=(const Copil&) = default;
//    Copil operator+(unsigned int x);

    friend istream& operator>>(istream& in, Copil& copil);
    friend ostream& operator<<(ostream& out, const Copil& copil);

    virtual void read(istream& in);
    virtual void print(ostream& out) const;

    void setNumarFapteBune(unsigned int numarFapteBune);

    const string &getNume() const;

    unsigned int getVarsta() const;

    void setJucarii(const vector<shared_ptr<Jucarie>> &jucarii);

    unsigned int getNumarFapteBune() const;

    const vector<shared_ptr<Jucarie>> &getJucarii() const;

    const int getIdCopil() const;
};


#endif //PROIECT_03_COPIL_H