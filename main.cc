#include <iostream>
#include <vector>
#include <string>
#include "Node.h"
#include "Graph.h" 
#include "dijkstra.h" 


int main(){
    Graph graph("graph.txt");

    std::string startNode, endNode;
    std::cout << "Ange startnod: ";
    std::cin >> startNode;
    std::cout << "Ange destinationsnod: ";
    std::cin >> endNode;

    Node* start = graph.find(startNode);
    Node* end = graph.find(endNode);

    if (!start || !end) {
        std::cerr << "Ogiltig start- eller slutnod\n";
        return 1;
    }

    graph.resetVals();
    dijkstra(start);

    std::cout << "Kortaste avstånd från " << startNode << " till " << endNode << ": " << end->getValue() << "\n";
    return 0;
}

