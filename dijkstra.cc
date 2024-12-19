#include <vector>
#include <iostream>
#include "dijkstra.h"
#include "NodeSet.h"
#include <limits>


/** Dijkstras algoritm. Varje nod som kan nås från start ges ett värde,
där värdet anger det kortaste avståndet från noden start.
Alla noder förutsätts, när funktionen anropas, ha ett värde som är
större än alla faktiska avstånd i grafen.
*/
Dijkstra::Dijkstra(Node* start){
    start->setValue(0);                                     //Sätter startnodes längd till sig själv till 0
    NodeSet dijkstraNodes{};                                //Skapar en tom nodeset
    dijkstraNodes.add(start);                               //Lägger till startnoden till nodeset
    
    while(!dijkstraNodes.isEmpty()){                        //Kör tills alla noder bearbetats och fått nya värden relativt startnoden
        Node *node = dijkstraNodes.removeMin();             //Tar ut en nod att arbeta med
        
        for(Edge edge : node->getEdges()){                  //Kör dijkstraalgoritmen för en nods alla edges mot andra noder
            int length = edge.getLength();                  //Tar ut längden för en edge
            Node *destNode = edge.getDestination();         //Tar ut dess destination
            int newLength = node->getValue() + length;      //Räknar ut dess värde relativt startnoden
            
            if (newLength < destNode->getValue()) {          // Kollar om det nya värdet är mindre än tidigare beräknad väg
                destNode->setValue(newLength);               // Uppdatera värdet för destinationen
                destNode->setParent(node);                   // Uppdatera parent (föregångaren) till den nuvarande noden
                dijkstraNodes.add(destNode);                 // Lägg till noden i mängden för bearbetning
            }        
        }
    }
}


void Dijkstra::printPath(Node* end) const {
    if (!end) {
        std::cerr << "Slutnoden är null!" << std::endl;
        return;
    }

    // Kontrollera om noden är nåbar
    if(end->getValue() == std::numeric_limits<int>::max()) {
        std::cout << "Ingen väg till " << end->getName() << " från startnoden." << std::endl;
        return;
    }

    // Samla vägen i en vektor
    std::vector<std::string> path;
    Node* current = end;

    // Backtracka med hjälp av parent-pekare
    while(current) {
        path.push_back(current->getName());
        current = current->getParent();
    }

    // Skriv ut vägen i rätt ordning
    for (auto it = path.rbegin(); it != path.rend(); ++it) {
        std::cout << *it << " ";
    }

    // Skriv ut det totala avståndet
    std::cout << end->getValue() << std::endl;
}


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
			int newLength = f(node, edge);
			Node *destNode = edge.getDestination();
			if (newLength < destNode->getValue())
			{
				destNode->setValue(newLength);
				destNode->setParent(node);
				generalDijkstraNodes.add(destNode);
			}
		}
	}
}