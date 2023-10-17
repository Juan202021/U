//
// Created by Juan on 10/13/2023.
//
#ifndef L4_PUNTO_CPP
#define L4_PUNTO_CPP
#include "Punto.h"

Punto::Punto():fil(-1),col(-1){}
Punto::Punto(int fil, int col):fil(fil),col(col){}
Punto::Punto(const Punto& p){
    fil = p.getFil();
    col = p.getCol();
}
int Punto::getFil() const{ return fil; }
void Punto::setFil(int fil){ this->fil = fil; }
int Punto::getCol() const{ return col; }
void Punto::setCol(int col){ this->col = col; }
bool Punto::operator==(const Punto& p) const{
    return (fil == p.getFil() && col == p.getCol());
}

#endif