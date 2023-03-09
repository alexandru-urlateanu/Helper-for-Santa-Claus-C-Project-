#ifndef PROIECT_03_COPILNEASTAMPARAT_H
#define PROIECT_03_COPILNEASTAMPARAT_H

#include "Copil.h"

#include <iostream>

using namespace std;

class CopilNeastamparat : public Copil {
private:
    int numarCarbuni{};

public:
    CopilNeastamparat() = default;
    ~CopilNeastamparat() override = default;
    CopilNeastamparat(const string &_nume, const string &_prenume, const string &_adresa, unsigned int _varsta,
                 unsigned int _numarFapteBune, const vector<shared_ptr<Jucarie>> &_jucarii, int _numarCarbuni);
    CopilNeastamparat(const CopilNeastamparat&) =  default;
    CopilNeastamparat &operator=(const CopilNeastamparat&) = default;

    void read(istream& in) override;
    void print(ostream& out) const override;
};


#endif //PROIECT_03_COPILNEASTAMPARAT_H