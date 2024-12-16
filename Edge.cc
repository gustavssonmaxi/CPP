#include "Edge.h"
 
<<<<<<< HEAD
//agien
=======
//test
>>>>>>> 4e0a742b28ea5287d85e971714d868549fa606b5
/** Skapa en ny båge till noden destination, med längden length. */
Edge::Edge(Node* destination, int length){
    destinationNode = destination;
    edgeLength = length;
}

/** Hämtar bågens destination. */
Node* Edge::getDestination(){
    return destinationNode;
}

/** Hämtar bågens längd. */
int Edge::getLength() const{
    return edgeLength;
}
