//
// Created by Juan on 10/4/2023.
//

#ifndef PILAYCOLA_STACK_H
#define PILAYCOLA_STACK_H

#include "List.h"
#include "Punto.h"

template<typename T>
class Stack {
protected:
    List<T> list;
public:
    Stack();
    Stack(const Stack<T>& stack);
    void push(const T& value);
    void pop();
    T& top();
    int size();
    void print();
};


#endif //PILAYCOLA_STACK_H
