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
    explicit Stack(List<T> list);
    Stack(Stack<T>& stack);
    ~Stack();
    void push(const T& value);
    void pop();
    T& top();
    int size();
    void print();
    Stack<T>& operator=(const Stack<T>& stack);
    void reverseContent();
};


#endif //PILAYCOLA_STACK_H
