#include "Edge.h"
 
 
/** Skapa en ny båge till noden destination, med längden length. */
Edge::Edge(Node* destination, int length){
    destinationNode = destination;
    edgeLength = length;
}

/** Hämtar bågens destination. */
Node* Edge::getDestination(){//this is a test
    return destinationNode;
}

/** Hämtar bågens längd. */
int Edge::getLength() const{
    return edgeLength;
}