#include "dijkstra.h"
#include "NodeSet.h"

#include <vector>

/** Dijkstras algoritm. Varje nod som kan nås från start ges ett värde,
där värdet anger det kortaste avståndet från noden start.
Alla noder förutsätts, när funktionen anropas, ha ett värde som är
större än alla faktiska avstånd i grafen.
*/
void dijkstra(Node* start){
    start->setValue(0);                             //Sätter startnodes längd till sig själv till 0
    NodeSet dijkstraNodes{};                        //Skapar en tom nodeset
    dijkstraNodes.add(start);                       //Lägger till startnoden till nodeset
    while(!dijkstraNodes.isEmpty()){            //Kör tills alla noder bearbetats och fått nya värden relativt startnoden
        Node *node = dijkstraNodes.removeMin();     //Tar ut en nod att arbeta med
        for(Edge edge : node->getEdges()){          //Kör dijkstraalgoritmen för en nods alla edges mot andra noder
            int length = edge.getLength();                  //Tar ut längden för en edge
            Node *destNode = edge.getDestination();         //Tar ut dess destination
            int newLength = node->getValue() + length;      //Räknar ut dess värde relativt startnoden
            if(newLength < destNode->getValue()){           //Kollar om det nya värdet är mindre än tidigare beräknad väg
                destNode->setValue(newLength);              //Om så är fallet uppdaterar med längd
                dijkstraNodes.add(destNode);                //och ny destnod
            }
        }
    }
}