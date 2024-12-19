#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Node.h"

/** Dijkstras algoritm. Varje nod som kan nås från start ges ett värde,
där värdet anger det kortaste avståndet från noden start.
Alla noder förutsätts, när funktionen anropas, ha ett värde som är
större än alla faktiska avstånd i grafen.
*/
/*
class Dijkstra {
 public:
     explicit Dijkstra(Node* start);
     void printPath(Node* end) const;
};
*/

void dijkstra(Node *start);
void printPath(Node *end);
void generalDijkstra(Node *start, int (*f)(Node *, Edge &));
#endif