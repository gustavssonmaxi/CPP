#include <iostream>
#include <fstream>
#include "Graph.h"
#include "dijkstra.h"
#include "Node.h"
#include <cassert>

int passedNodes(Node *, Edge &);
int countedChars(Node *, Edge &);

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

        // Kör Dijkstra-algoritmen med startnoden
        graph.resetVals();
        Dijkstra dijkstra(start);

        // Anropa Dijkstra för att skriva ut vägen och avståndet
        dijkstra.printPath(end);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Fel: " << e.what() << std::endl;
        return 1;
    }

    return 0;

}

/* Räknar upp antalet noder passerade i grafen*/
int passedNodes(Node *node, Edge &e)
{
    (void) e; //Använder inte edge i denna funktion
    int count = 1;
    while (node->getParent() != nullptr)
    {
        ++count;
        node = node->getParent();
    }
    return count;
}
/* Räknar upp antalet tecken för varje nod i grafen
 * som man har passerat*/
int countedChars(Node *node, Edge &e)
{

    int count = 0;
    while (node->getParent() != nullptr)
    {
        count += node->getName().length();
        node = node->getParent();
    }
    count += e.getDestination()->getName().length();

    return count;
}

/* main för testa generalDijkstra
    std::cout << "Hello Dijkstra fan!" << std::endl
         << std::endl;

    Graph g{};

    g.addNode("Sweden");
    g.addNode("Qatar");
    g.addNode("Atlantis");
    g.addNode("Russia");
    g.addNode("Denmark");

    g.find("Sweden")->addEdge(g.find("Denmark"), 10);
    g.find("Sweden")->addEdge(g.find("Russia"), 20);

    g.find("Denmark")->addEdge(g.find("Sweden"), 10);
    g.find("Denmark")->addEdge(g.find("Russia"), 5);
    g.find("Denmark")->addEdge(g.find("Qatar"), 30);

    g.find("Russia")->addEdge(g.find("Sweden"), 20);
    g.find("Russia")->addEdge(g.find("Qatar"), 10);
    g.find("Russia")->addEdge(g.find("Denmark"), 5);

    g.find("Qatar")->addEdge(g.find("Russia"), 10);
    g.find("Qatar")->addEdge(g.find("Denmark"), 30);
    g.find("Qatar")->addEdge(g.find("Atlantis"), 20);

    g.find("Atlantis")->addEdge(g.find("Qatar"), 20);

    dijkstra(g.find("Sweden"));
    printPath(g.find("Qatar"));
    assert(g.find("Qatar")->getValue() == 25);

    printPath(g.find("Russia"));
    assert(g.find("Russia")->getValue() == 15);

    g.resetVals();

    generalDijkstra(g.find("Sweden"), passedNodes);
    printPath(g.find("Denmark"));

    g.resetVals();

    generalDijkstra(g.find("Sweden"), countedChars);
    printPath(g.find("Atlantis"));

    */