#ifndef SFML1_GRAPH_H
#define SFML1_GRAPH_H
#include <iostream>
#include "List.cpp"
#include "SFML/Graphics.hpp"

using namespace std;

template<class T>
class Edge;
template<class T>
class Vertex;

class CircleClass{
public:
    sf::CircleShape circle;
    int id;
    CircleClass();
    CircleClass(sf::CircleShape circle, int id);
};

template<class T>
class Edge{
public:
    Vertex<T>* to;
    int weight;
    friend ostream &operator<<(ostream &out, Edge<T>* edge) {
        out << "To: " << edge->to->data << ", Weight: " << edge->weight << endl;
        return out;
    }
};

template<class T>
class Vertex{
public:
    T data;
    int inDegree;
    int outDegree;
    List<Edge<T>*> connectedTo;

    Vertex<T>* predecessor;
    int distance;
    char color;

    Vertex(const T& value);
    ~Vertex();
    void addNeighbor(Vertex<T>* to, int weight=0);
    int getWeight(const T& value);
    friend ostream &operator<<(ostream &out, Vertex<T>* vertex) {
        out << vertex->data << endl;
        out << "In degree: " << vertex->inDegree << endl;
        out << "out degree: " << vertex->outDegree << endl;
        out << "Edges: " << endl;
        vertex->connectedTo.print();
        return out;
    }
};

template<class T>
class Graph {
public:
    int count;
    List<Vertex<T>*> vertexList;
    Graph();
    ~Graph();
    Vertex<T>* addVertex(const T& value);
    Vertex<T>* getVertex(const int& value);
    void addEdge(const int& from, const int& to, int weight=0);
};
#endif