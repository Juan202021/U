#ifndef L5_BINARYTREE_CPP
#define L5_BINARYTREE_CPP

#include "BinaryTree.h"

template<class T>
NodeTree<T> *NodeTree<T>::makeNode(const T &value) {
    NodeTree<T>* temp = new NodeTree<T>;
    temp->data = value;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}
template<class T>
void NodeTree<T>::insertLeft(const T &value) {
    if(!left){
        left = makeNode(value);
    }else{
        NodeTree<T>* temp = makeNode(value);
        temp->left = left;
        left = temp;
    }
}
template<class T>
void NodeTree<T>::insertRight(const T &value) {
    if(!right){
        right = makeNode(value);
    }else{
        NodeTree<T>* temp = makeNode(value);
        temp->right = right;
        right = temp;
    }
}
template<class T>
void BinaryTree<T>::destroy(NodeTree<T> *ptr) {
    if(!ptr) return;
    destroy(ptr->left);
    destroy(ptr->right);
    delete ptr;
}
template<class T>
BinaryTree<T>::BinaryTree(const T &value) {
    root = root->makeNode(value);
}
template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &tree) {
    root = tree.root;
    count = tree.count;
}

template<class T>
BinaryTree<T>::~BinaryTree() {
    destroy(root);
}
template<class T>
void BinaryTree<T>::setRoot(const T &value) {
    root = root->makeNode(value);
}
template<class T>
NodeTree<T>* BinaryTree<T>::getRoot(){
    return root;
}
template<class T>
void BinaryTree<T>::print4(NodeTree<T> *ptr,int nivel) {
    nivel = getTreeHeight(ptr);
    if (ptr == nullptr) {
        return;
    }

    while(true){
        //std::cout << ptr->data << std::endl;

        for (int i = 0; i < 3; i++) {
            std::cout <<ptr->left->data;
            for (int i = 0; i < nivel; i++) {
                        std::cout << "   ";
                    }
            std::cout << ptr->right->data;
        }
        std::cout<<std::endl;

        std::cout << ptr->data<<std::endl;
        nivel = getTreeHeight(root);
        print4(ptr->left,nivel-1);

        nivel = getTreeHeight(root);
        print4(ptr->right, nivel +1);
        //
        break;

    }
}


template<class T>
void BinaryTree<T>::print(NodeTree<T>* ptr){
    if (!ptr) return ;
    print(ptr->left);
    std::cout<< ptr->data<<" ";
    print(ptr->right);
}

template<class T>
void BinaryTree<T>::print(){
     print4(root,0);
}

template<class T>
std::string BinaryTree<T>::printPosOrden(NodeTree<T>* ptr){
    if (!ptr) return "";
    if (ptr->left == nullptr && ptr->right == nullptr) {
        return ptr->data;
    }
    return printPosOrden(ptr->left) + " " + printPosOrden(ptr->right) + " " + ptr->data;
}

template<class T>
void BinaryTree<T>::printPosOrden(){
     std::cout << printPosOrden(root);
}

template<class T>
int BinaryTree<T>::getNumLeaves(NodeTree<T>* ptr){
    if(!ptr) return 0;
    if (ptr->left == nullptr && ptr->right == nullptr) {
        // Es una hoja
        return 1;
    }
    // Recorrer de manera recursiva los hijos izquierdo y derecho
    return getNumLeaves(ptr->left) + getNumLeaves(ptr->right);
}
template<class T>
void BinaryTree<T>::getNumLeaves(){
    std::cout << "La cantidad de hojas del arbol [" << root->data << "] es: " << getNumLeaves(root) << std::endl;
}

template<class T>
int BinaryTree<T>::getCountNodes(NodeTree<T> *ptr) const {
    if (!ptr) return 0;
    return getCountNodes(ptr->left) + getCountNodes(ptr->right) + 1;
}

template<class T>
void BinaryTree<T>::getCountNodes(){
    std::cout << "La cantidad de nodos del arbol [" << root->data << "] es: "<< getCountNodes(this->root) << std::endl;
}

int max(int& a, int& b) {
    return (a > b) ? a : b;
}

template<class T>
int BinaryTree<T>::getTreeHeight(NodeTree<T> *ptr) const {
    if (!ptr) return 0;
    int left_height = getTreeHeight(ptr->left);
    int right_height = getTreeHeight(ptr->right);
    return max(left_height, right_height) + 1;
}
template<class T>
void BinaryTree<T>::getTreeHeight(){
    std::cout <<"La altura del arbol [" << root->data << "] es: " << getTreeHeight(this->root) - 1 << std::endl;
}

template<class T>
void BinaryTree<T>::getBalanceFactor(NodeTree<T> *ptr){
    int leftHeight = getTreeHeight(ptr->left);
    int rightHeight = getTreeHeight(ptr->right);
    std::cout << "El balance de [" << ptr->data << "] es de: " << (leftHeight - rightHeight) << std::endl;
}

template class BinaryTree<std::string>;
template class NodeTree<std::string>;

#endif