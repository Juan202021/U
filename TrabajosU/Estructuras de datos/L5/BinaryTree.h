#ifndef L5_BINARYTREE_H
#define L5_BINARYTREE_H

#include <iostream>

template<class T>
struct NodeTree{
    T data;
    NodeTree<T>* left;
    NodeTree<T>* right;
    NodeTree<T>* makeNode(const T& value);
    void insertLeft(const T& value);
    void insertRight(const T& value);
};

template<class T>
class BinaryTree {
    int getCountNodes(NodeTree<T> *ptr) const;
    int getTreeHeight(NodeTree<T> *ptr) const;
    int getNumLeaves(NodeTree<T>* ptr);
    void print(NodeTree<T>* cur);
    std::string printPosOrden(NodeTree<T>* cur);
    void print3(NodeTree<T> *ptr, int nivel);
    void print4(NodeTree<T> *ptr, int nivel);
protected:
    NodeTree<T>* root;
    int count;
    void destroy(NodeTree<T> *ptr);
public:
    BinaryTree(const T& value);
    BinaryTree(const BinaryTree<T>& tree);
    ~BinaryTree();
    void setRoot(const T& value);
    NodeTree<T>* getRoot();
    void getNumLeaves();
    void getCountNodes();
    void getTreeHeight();
    void getBalanceFactor(NodeTree<T>* ptr);
    void print();
    void printPosOrden();
};


#endif //L5_BINARYTREE_H
