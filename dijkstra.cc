// #include <vector>
#include <iostream>
// #include <limits>
#include "dijkstra.h"
#include "NodeSet.h"

/** Dijkstras algoritm. Varje nod som kan nås från start ges ett värde,
där värdet anger det kortaste avståndet från noden start.
Alla noder förutsätts, när funktionen anropas, ha ett värde som är
större än alla faktiska avstånd i grafen.
*/
void dijkstra(Node *start)
{
    start->setValue(0);
    NodeSet dijkstraNodes{};
    dijkstraNodes.add(start);

    while (!dijkstraNodes.isEmpty())
    {
        Node *node = dijkstraNodes.removeMin();

        for (Edge edge : node->getEdges())
        {
            int length = edge.getLength();
            Node *destNode = edge.getDestination();
            int newLength = node->getValue() + length;

            if (newLength < destNode->getValue())
            {
                destNode->setValue(newLength);
                destNode->setParent(node);
                dijkstraNodes.add(destNode);
            }
        }
    }
}

/** Skriver ut noderna på vägen från start till end. */
void printPath(Node *end)
{
    if (!end)
    {
        std::cerr << "Slutnoden är null!" << std::endl;
        return;
    }

    if (end->getValue() == std::numeric_limits<int>::max())
    {
        std::cout << "Ingen väg till " << end->getName() << " från startnoden." << std::endl;
        return;
    }

    std::vector<std::string> path;
    Node *current = end;

    // Backtracka med hjälp av parent-pekare
    while (current)
    {
        path.push_back(current->getName());
        current = current->getParent();
    }

    for (auto it = path.rbegin(); it != path.rend(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << end->getValue() << std::endl;
}

/** En generel Dijkstraalgoritm som tar in en startnod och en
funktion. Funktionen avgör vad noden ska få för value
sett till startnoden.
*/
void generalDijkstra(Node *start, int (*f)(Node *, Edge &))
{
    start->setValue(0);
    NodeSet generalDijkstraNodes{};
    generalDijkstraNodes.add(start);
    while (!generalDijkstraNodes.isEmpty())
    {
        Node *node = generalDijkstraNodes.removeMin();
        for (Edge edge : node->getEdges())
        {
            int length = f(node, edge);
            Node *destNode = edge.getDestination();
            if (length < destNode->getValue())
            {
                destNode->setValue(length);
                destNode->setParent(node);
                generalDijkstraNodes.add(destNode);
            }
        }
    }
}