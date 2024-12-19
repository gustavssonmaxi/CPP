#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Node.h"

/** Dijkstras algoritm. Varje nod som kan nås från start ges ett värde,
där värdet anger det kortaste avståndet från noden start.
Alla noder förutsätts, när funktionen anropas, ha ett värde som är
större än alla faktiska avstånd i grafen.
*/
void dijkstra(Node *start);

// Skriver ut noderna på vägen från start till end.
void printPath(Node *end);

// En generel Dijkstraalgoritm som tar in en startnod och en
// funktion. Funktionen avgör vad nodsen ska få för value
// sett till startnoden.
void generalDijkstra(Node *start, int (*f)(Node *, Edge &));
#endif