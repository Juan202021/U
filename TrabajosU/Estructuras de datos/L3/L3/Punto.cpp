//
// Created by santi on 23/09/2023.
//

#ifndef PUNTO_CPP
#define PUNTO_CPP
#include "Punto.h"

template <typename T>
Punto<T>::Punto():x(0.0),y(0.0){}
template <typename T>
Punto<T>::Punto(T x, T y):x(x),y(y){}
template<typename T>
Punto<T>::~Punto(){};
template <typename T>
T Punto<T>::getX(){return x;}
template <typename T>
T Punto<T>::getY(){return y;}
template <typename T>
void Punto<T>::setX(T x){this->x=x;}
template <typename T>
void Punto<T>::setY(T y){this->y=y;}

/*template <typename T>
ostream& operator<<(ostream& out, const Punto<T> &p){
    out<<"x: "<<p.x<<" y: "<<p.y<<endl;
    return out;
}*/

template class Punto<double>;
#endif