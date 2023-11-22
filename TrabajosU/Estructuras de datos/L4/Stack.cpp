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
Stack<T>::Stack(List<T> list){
    this->list = list;
}
template <typename T>
Stack<T>::Stack(Stack<T>& stack){
    list = stack.list;
}
template <typename T>
Stack<T>::~Stack() {
    list.~List();
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
    list.printReverse();
    cout << endl;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& stack){
    if(this != &stack){ //Comprueba que no se esté intentanod igualar un objeto a sí mismo
        this->list = stack.list;
    }
    return *this;
}

template <typename T>
void Stack<T>::reverseContent(){
    Stack<T> stack;
    while (this->size() > 0){
        stack.push(this->top());
        this->pop();
    }
    *this = stack;
}

template class Stack<Punto>;

#endif