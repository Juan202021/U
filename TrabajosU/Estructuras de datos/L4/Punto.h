//
// Created by Juan on 10/13/2023.
//

#ifndef L4_PUNTO_H
#define L4_PUNTO_H
#include <iostream>
using namespace std;

class Punto {
    int fil,col;
public:
    Punto();
    Punto(int fil, int col);
    Punto(const Punto& p);
    int getFil() const;
    void setFil(int fil);
    int getCol() const;
    void setCol(int col);
    friend ostream& operator<<(ostream& out, const Punto& p){
        out << "Punto(x: " << p.fil << ", y: " << p.col << ")";
        return out;
    }
};

#endif //L4_PUNTO_H
