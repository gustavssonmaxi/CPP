#include <iostream>
#include <fstream>
#include "Graph.h"
#include "dijkstra.h"

int main() {
    const std::string fileName = "graf.txt"; // Fast filnamn
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        std::cerr << "Kunde inte öppna filen: " << fileName << std::endl;
        return 1;
    }

    try {
        // Skapa grafen från indatafilen
        Graph graph(inputFile);
        std::cout << "Grafen har skapats framgångsrikt från filen: " << fileName << std::endl;

        // Fråga användaren efter start- och slutnod
        std::string startNode, endNode;
        std::cout << "Ange startnod: ";
        std::cin >> startNode;
        std::cout << "Ange slutnod: ";
        std::cin >> endNode;

        // Hitta startnoden i grafen
        Node* start = graph.find(startNode);
        if (!start) {
            std::cerr << "Startnoden '" << startNode << "' finns inte i grafen." << std::endl;
            return 1;
        }

        // Kör Dijkstra-algoritmen med startnoden
        dijkstra(start);

        // Hitta slutnoden
        Node* end = graph.find(endNode);
        if (!end) {
            std::cerr << "Slutnoden '" << endNode << "' finns inte i grafen." << std::endl;
            return 1;
        }

        // Anropa Dijkstra för att skriva ut vägen och avståndet
        // dijkstra.printPath(end);

    } catch (const std::exception& e) {
        std::cerr << "Fel: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}