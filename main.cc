#include <iostream>
#include <fstream>
#include "Graph.h"
#include "dijkstra.h"
#include "Node.h"
#include <limits>

// Funktion för att räkna steg (antal hopp)
int countSteps(Node *node, Edge &)
{
    return node->getValue() + 1; // Ett hopp läggs till för varje edge
}

// Main för köra ett interaktivt program som utifrån användarens val kan köra en vanlig
// Dijktras algoritm från en startnod till en ändnod i en graf som innehåller noderna i
// graft.txt. Går även att köra en modifierad algoritm som kan ta den väg med minst antal
// noder mellan start och ändnoden. Går även att definera en ny funktion och stoppa in i
// generalDijkstra för att ändra dess vägval.
int main()
{
    const std::string fileName = "graf.txt"; // Fast filnamn
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open())
    {
        std::cerr << "Kunde inte öppna filen: " << fileName << std::endl;
        return 1;
    }

    try
    {
        // Skapa grafen från indatafilen
        Graph graph(inputFile);
        std::cout << "Grafen har skapats framgångsrikt från filen: " << fileName << std::endl;

        // Fråga användaren efter start- och slutnod
        std::string startNode, endNode;
        std::cout << "Ange startnod: ";
        std::getline(std::cin >> std::ws, startNode);
        std::cout << "Ange slutnod: ";
        std::getline(std::cin >> std::ws, endNode);

        // Hitta startnoden i grafen
        Node *start = graph.find(startNode);
        if (!start)
        {
            std::cerr << "Startnoden '" << startNode << "' finns inte i grafen." << std::endl;
            return 1;
        }

        // Hitta slutnoden
        Node *end = graph.find(endNode);
        if (!end)
        {
            std::cerr << "Slutnoden '" << endNode << "' finns inte i grafen." << std::endl;
            return 1;
        }

        // Fråga användaren om kriterium
        char choice;
        std::cout << "Välj beräkningskriterium:\n"
                  << "A) Kortaste väg enligt avstånd\n"
                  << "B) Kortaste väg enligt antal steg\n"
                  << "Val: ";
        std::cin >> choice;

        // Kör algoritmen baserat på användarens val
        graph.resetVals();
        if (choice == 'A' || choice == 'a')
        {
            dijkstra(start); // Klassisk Dijkstra
            printPath(end);
        }
        else if (choice == 'B' || choice == 'b')
        {
            generalDijkstra(start, countSteps); // Generaliserad Dijkstra med antal steg
            if (end->getValue() == std::numeric_limits<int>::max())
            {
                std::cout << "Ingen väg hittades från " << startNode << " till " << endNode << ".\n";
            }
            else
            {
                printPath(end);
            }
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