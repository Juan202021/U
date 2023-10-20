//
// Created by Juan on 10/13/2023.
//

#ifndef L4_PUNTO_H
#define L4_PUNTO_H
#include <iostream>
using namespace std;

class Punto {
    int fil,col,cantAlternativas;
public:
    Punto();
    Punto(int fil, int col, int cantAlternativas);
    Punto(const Punto& p);
    int getFil() const;
    void setFil(int fil);
    int getCol() const;
    void setCol(int col);
    int getCantAlternativas() const;
    void setCantAlternativas(int cantAlternativas);
    bool operator==(const Punto& p) const;
    friend ostream& operator<<(ostream& out, const Punto& p);
};

#endif //L4_PUNTO_H
