#ifndef EDGE_H
#define EDGE_H

#include <string>

/** Forward deklaration av Node */
class Node;

class Edge
{
public:
    /** Skapa en ny båge till noden destination, med längden length. */
    Edge(Node *destination, int length);

    /** Hämtar bågens destination. */
    Node *getDestination() const;

    /** Hämtar bågens längd. */
    int getLength() const;

private:
    Node *destinationNode;
    int edgeLength;
};
#endif