//
// Created by santi on 23/09/2023.
//
#include <iostream>

#ifndef LAB3_PUNTO_H
#define LAB3_PUNTO_H
using namespace std;
template <typename T>
class Punto {
    T x;
    T y;
public:
    Punto();
    Punto(T x, T y);
    ~Punto();
    T getX();
    T getY();
    void setX(T x);
    void setY(T y);
    friend ostream& operator<<(ostream& out, const Punto<T> &p){
        out << "Punto(x: " << p.x << ", y: " << p.y << ")";
        return out;
    };
};

#endif //LAB3_PUNTO_H
