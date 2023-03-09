#ifndef PROIECT_03_MENIU_H
#define PROIECT_03_MENIU_H

#include "Copil.h"

#include <iostream>

using namespace std;

class Meniu {
private:
    static Meniu* instance;
    Meniu() = default;
    vector<shared_ptr<Copil>> copii;
public:
    ~Meniu() = default;
    static Meniu* getInstance();

    static void meniu();
    void adaugareCopii();
    void afisareCopii();
    void cautaCopil(const string& numeCopil);
    void ordonareVarsta();
    void ordonareFapteBune();
    void adaugareFapteBune(int idCopil, int numarFapteBune);
    void raportJucarii();
};

#endif //PROIECT_03_MENIU_H