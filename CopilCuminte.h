#ifndef PROIECT_03_COPILCUMINTE_H
#define PROIECT_03_COPILCUMINTE_H

#include "Copil.h"

#include <iostream>

using namespace std;

class CopilCuminte : public Copil {
private:
    int numarDulciuri{};

public:
    CopilCuminte() = default;
    ~CopilCuminte() override = default;
    CopilCuminte(const string &_nume, const string &_prenume, const string &_adresa, unsigned int _varsta,
                 unsigned int _numarFapteBune, const vector<shared_ptr<Jucarie>> &_jucarii, int _numarDulciuri);
    CopilCuminte(const CopilCuminte&) =  default;
    CopilCuminte &operator=(const CopilCuminte&) = default;

    void read(istream& in) override;
    void print(ostream& out) const override;
};


#endif //PROIECT_03_COPILCUMINTE_H