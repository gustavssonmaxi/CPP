#ifndef NODESET_H
#define NODESET_H
#include <vector>

class Node; // Forward deklaration

class NodeSet
{

public:
    /** Skapar en tom mängd av noder. */
    NodeSet();
    /** Lägger till noden node till mängden,
    om mängden inte redan innehåller en nod med samma namn. */
    void add(Node *node);
    /** Returnerar true om mängden noder är tom. */
    bool isEmpty();
    /** Väljer ut den nod som har lägst värde och returnerar den.
    Den returnerade noden tas bort ur mängden.
    Om mängden är tom returneras null. */
    Node *removeMin();

private:
    /**Vektorn som innehåller nodsen i mängden NodeSet */
    std::vector<Node *> nodeVector;
};
#endif