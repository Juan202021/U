#ifndef LAB3_LIST_H
#define LAB3_LIST_H

#include <windows.h>
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
    List(Node<T>* begin, int count);
    ~List();
    List(const List<T>& list);
    void insert(int pos, const T& value);
    int size() const;
    void erase(int pos);
    T& get(int pos) const;
    void print() const;
    void printReverse() const;
    List<T>& operator=(const List<T>& list);
};
#endif //LAB3_LIST_H
