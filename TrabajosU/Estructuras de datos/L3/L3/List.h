//
// Created by santi on 23/09/2023.
//

#ifndef LAB3_LIST_H
#define LAB3_LIST_H


#include <iostream>
#include <cassert>
using namespace std;

template<typename T>
struct Node
{
    T data;
    Node<T>* next;
};

template<typename T>
class List{
private:
    Node<T>* begin;
    int count;
    Node<T>* makeNode(const T& value);
public:
    List();
    ~List();
    void insert(int pos, const T& value);
    int size() const;
    void erase(int pos);
    T& get(int pos) const;
    void print() const;
    void printReverse() const;

};
#endif //LAB3_LIST_H
