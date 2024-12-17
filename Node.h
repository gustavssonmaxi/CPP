#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>
#include "Edge.h"

// Forward declaration Edge
class Edge;

class Node{

public:

    /** Skapar en nod med givet namn, utan bågar och med maximalt värde. */
    Node(const std::string& name);
    
    /** Hämtar nodens namn. */
    std::string getName() const;

    /** Sätter nodens värde till v. */
    void setValue(int v);

    /** Hämtar nodens värde. */
    int getValue() const;

    /** Lägger till en ny båge från denna nod till en given destination.
     Bågen ska ha längden length. */
    void addEdge(Node* destination, int length);

    /** Hämtar de bågar som utgår från denna nod. */
    const std::vector<Edge>& getEdges() const;

    /** Sätter föregångaren (parent) för kortaste vägen. */
    void setParent(Node* p);

    /** Hämtar föregångaren (parent) för kortaste vägen. */
    Node* getParent() const;

private:
    std::string nodeName;
    int nodeValue;
    std::vector<Edge> edgeVector;   
    Node* parent; // Ny medlemsvariabel för att spåra föregångaren
    
};
 #endif