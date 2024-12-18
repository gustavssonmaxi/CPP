#include <iostream>
#include <fstream>
#include "Graph.h"
#include "dijkstra.h"
#include "Node.h"

int passedNodes(Node *, Edge &);
int countedChars(Node *, Edge &);

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

        // Hitta slutnoden
        Node* end = graph.find(endNode);
        if (!end) {
            std::cerr << "Slutnoden '" << endNode << "' finns inte i grafen." << std::endl;
            return 1;
        }


        // Kör Dijkstra-algoritmen med startnoden
        graph.resetVals();
        Dijkstra dijkstra(start);

        // Anropa Dijkstra för att skriva ut vägen och avståndet
        dijkstra.printPath(end);

    } catch (const std::exception& e) {
        std::cerr << "Fel: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}



// /* Räknar upp antalet noder passerade i grafen*/
// int passedNodes(Node *node, Edge &e)
// {

//     int count = 1;
//     while (node->getParent() != nullptr)
//     {
//         ++count;
//         node = node->getParent();
//     }
//     return count;
// }
// /* Räknar upp antalet tecken för varje nod i grafen
//  * som man har passerat*/
// int countedChars(Node *node, Edge &e)
// {

//     int count = 0;
//     while (node->getParent() != nullptr)
//     {
//         count += node->getName().length();
//         node = node->getParent();
//     }
//     count += e.getDestination()->getName().length();

//     return count;
// }
