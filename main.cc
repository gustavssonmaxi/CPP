#include <iostream>
#include <vector>
#include <string>
// #include "Node.h"
// #include "Graph.h" 
// #include "dijkstra.h" 


int main(){

    // Graph graph("graph.txt");

    std::string startName, endName;
    std::cout << "Ange startnod: ";
    std::cin >> startName;
    std::cout << "Ange destinationsnod: ";
    std::cin >> endName;

/*  Node* start = graph.findNode(startNode);
    Node* end = graph.findNode(endNode);

    if (!start || !end) {
        std::cerr << "Ogiltig start- eller slutnod\n";
        return 1;
    }

    graph.resetNodes();
    dijkstra(start);

    std::cout << "Kortaste avstånd från " << startNode << " till " << endNode << ": " << end->getValue() << "\n";
    return 0;
    */
}

