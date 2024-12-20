#include <iostream>
#include <fstream>
// #include <limits>
#include "Graph.h"
#include "dijkstra.h"
// #include "Node.h"

int countSteps(Node *node, Edge &)
{
    return node->getValue() + 1;
}

/** Main för köra ett interaktivt program som utifrån användarens val kan köra en vanlig
Dijktras algoritm från en startnod till en ändnod i en graf som innehåller noderna i
graft.txt. Går även att köra en modifierad algoritm som kan ta den väg med minst antal
noder mellan start och ändnoden. Går även att definera en ny funktion och stoppa in i
generalDijkstra för att ändra dess vägval.
*/
int main()
{
    const std::string fileName = "graf.txt";
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open())
    {
        std::cerr << "Kunde inte öppna filen: " << fileName << std::endl;
        return 1;
    }

    try
    {
        Graph graph(inputFile);
        std::cout << "Grafen har skapats framgångsrikt från filen: " << fileName << std::endl;

        std::string startNode, endNode;
        std::cout << "Ange startnod: ";
        std::getline(std::cin >> std::ws, startNode);
        std::cout << "Ange slutnod: ";
        std::getline(std::cin >> std::ws, endNode);

        Node *start = graph.find(startNode);
        if (!start)
        {
            std::cerr << "Startnoden '" << startNode << "' finns inte i grafen." << std::endl;
            return 1;
        }

        Node *end = graph.find(endNode);
        if (!end)
        {
            std::cerr << "Slutnoden '" << endNode << "' finns inte i grafen." << std::endl;
            return 1;
        }

        char choice;
        std::cout << "Välj beräkningsalternativ:\n"
                  << "A) Kortaste väg enligt avstånd\n"
                  << "B) Kortaste väg enligt antal steg\n"
                  << "Val: ";
        std::cin >> choice;

        graph.resetVals();
        if (choice == 'A' || choice == 'a')
        {
            dijkstra(start);
            printPath(end);
        }
        else if (choice == 'B' || choice == 'b')
        {
            generalDijkstra(start, countSteps);
            printPath(end);
        }
        else
        {
            std::cerr << "Ogiltigt val! Avbryter programmet.\n";
            return 1;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Fel: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}