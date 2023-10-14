//
// Created by Juan on 10/4/2023.
//
#ifndef STACK_CPP
#define STACK_CPP
#include "Stack.h"
#include "Punto.h"

template <typename T>
Stack<T>::Stack() {}

template <typename T>
Stack<T>::Stack(const Stack<T>& stack){
    list = stack.list;
}

template <typename T>
void Stack<T>::push(const T& value){
    list.insert(0,value);
}
template <typename T>
void Stack<T>::pop(){
    list.erase(0);
}
template <typename T>
T& Stack<T>::top(){
    return list.get(0);
}
template <typename T>
int Stack<T>::size(){
    return list.size();
}
template <typename T>
void Stack<T>::print(){
    list.print();
    cout << endl;
}

template class Stack<Punto>;

#endif