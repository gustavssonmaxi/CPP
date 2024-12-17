#include "Node.h"
#include "Edge.h"
#include <limits>

/** Skapar en nod med givet namn, utan bågar och med maximalt värde. */
Node::Node(const std::string& name){
    nodeName = name;
    nodeValue = std::numeric_limits<int>::max();
    edgeVector = {};
}
    
 /** Hämtar nodens namn. */
std::string Node::getName() const{
    return nodeName;
}

/** Sätter nodens värde till v. */
void Node::setValue(int v){
    nodeValue = v;
}

/** Hämtar nodens värde. */
int Node::getValue() const{
    return nodeValue;
}

/** Lägger till en ny båge från denna nod till en given destination.
Bågen ska ha längden length. */
void Node::addEdge(Node* destination, int length){
    edgeVector.push_back(Edge(destination, length));
}

/** Hämtar de bågar som utgår från denna nod. */
const std::vector<Edge>& Node::getEdges() const{
    return edgeVector;
}

/** Sätter föregångaren (parent) för kortaste vägen. */
void Node::setParent(Node* p) {
    parent = p;
}

/** Hämtar föregångaren (parent) för kortaste vägen. */
Node* Node::getParent() const {
    return parent;
}