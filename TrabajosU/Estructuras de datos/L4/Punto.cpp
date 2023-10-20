//
// Created by Juan on 10/13/2023.
//
#ifndef L4_PUNTO_CPP
#define L4_PUNTO_CPP
#include "Punto.h"

Punto::Punto():fil(-1),col(-1),cantAlternativas(0){}
Punto::Punto(int fil, int col, int cantAlternativas):fil(fil),col(col),cantAlternativas(cantAlternativas){}
Punto::Punto(const Punto& p){
    fil = p.getFil();
    col = p.getCol();
    cantAlternativas = p.cantAlternativas;
}
int Punto::getFil() const{ return fil; }
void Punto::setFil(int fil){ this->fil = fil; }
int Punto::getCol() const{ return col; }
void Punto::setCol(int col){ this->col = col; }
int Punto::getCantAlternativas() const { return cantAlternativas; }
void Punto::setCantAlternativas(int cantAlternativas) { this->cantAlternativas = cantAlternativas; }
ostream& operator<<(ostream& out, const Punto& p){
    out << "Punto(x: " << p.fil << ", y: " << p.col << ", cant: " << p.cantAlternativas << ")";
    return out;
}
bool Punto::operator==(const Punto& p) const{
    return (fil == p.getFil() && col == p.getCol());
}

#endif