#include <iostream>
#include "BinaryTree.h"

using namespace std;

BinaryTree<string> crearArbol(){
    BinaryTree<string> arbol("a");
    arbol.getRoot()->insertLeft("b");
    arbol.getRoot()->insertRight("c");
    arbol.getRoot()->left->insertRight("d");
    arbol.getRoot()->right->insertLeft("e");
    arbol.getRoot()->right->insertRight("f");
    return arbol;
}

int main() {
    BinaryTree<string> arbol = crearArbol();
    arbol.getBalanceFactor(arbol.getRoot());
    arbol.getBalanceFactor(arbol.getRoot()->left);
    arbol.getBalanceFactor(arbol.getRoot()->right);


    /*
    arbol.getCountNodes();
    arbol.getNumLeaves();
    arbol.getTreeHeight();
    arbol.getBalanceFactor(arbol.getRoot());
    arbol.getBalanceFactor(arbol.getRoot()->left);
    arbol.getBalanceFactor(arbol.getRoot()->right);*/

    //arbol.printPosOrden();
    //arbol.print();


    return 0;
}

