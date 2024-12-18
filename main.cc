#include <iostream>
#include <vector>
#include <string>
#include "Node.h"
#include "Graph.h"
#include "dijkstra.h"

int main() {
    // väntar på iostream? i konstruktorn
    Graph graph("graf.txt");

    std::string startNode, endNode;
    std::cout << "Ange startnod: ";
    std::cin >> startNode;
    std::cout << "Ange destinationsnod: ";
    std::cin >> endNode;

    // Hitta start- och slutnoder
    Node* start = graph.find(startNode);
    Node* end = graph.find(endNode);

    if (!start || !end) {
        std::cerr << "Ogiltig start- eller slutnod\n";
        return 1;
    }

    // Återställ noder och kör dijkstra
    graph.resetVals();
    dijkstra(start);

    // Kontrollera om en väg hittades
 /*   if (end->getValue() == std::numeric_limits<int>::max()) {
        std::cout << "Ingen väg hittades mellan " << startNode << " och " << endNode << "\n";
        return 1;
    }*/

    // Samla alla noder längs vägen från mål till start
    std::vector<std::string> path;
    Node* current = end;

    while (current) {
        path.push_back(current->getName());
        current = current->getParent();
    }

    std::cout << "Kortaste väg: ";
    for (const auto& name : path) {
        std::cout << name << " ";
    }
    std::cout << end->getValue() << "\n";
    return 0;
}