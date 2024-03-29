#ifndef LAB3_LIST_H
#define LAB3_LIST_H

#include <iostream>
#include <cassert>
#include <vector>
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
    List(const List<T>&);
    void insert(int pos, const T& value);
    int size() const;
    void erase(int pos);
    T& get(int pos) const;
    void print() const;
    void printReverse() const;
    List& operator=(const List<int> &l);
    bool operator==(List<int> &l);
    List<int> operator+(List<int> &l);
    List<int>& operator++();
    List<int> operator*(List<int> &l);
    void crear_ngrande();
    void archivo(vector<List<int>>& listas);
};
#endif //LAB3_LIST_H
