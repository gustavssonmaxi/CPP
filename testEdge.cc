#include "Edge.h"
#include "Node.h"
#include <iostream>

int main(){
    /*
    Node N("Lund");
    Edge E(&N, 5);
    std::cout << "Stad: "<< E.getDestination()->getName() << ", Avstånd: "<<E.getLength() << std::endl;
    */
   Node lund{"Lund"};
    Node dalby{"Dalby"};
    Node sandby{"Sodra Sandby"};
    Node hallestad{"Torna Hallestad"};
    Node flyinge{"Flyinge"};
    Node veberod{"Veberod"};
    lund.addEdge(&dalby,12);
    lund.addEdge(&sandby,12);
    dalby.addEdge(&veberod,11);
    dalby.addEdge(&hallestad,5);
    sandby.addEdge(&lund,12);
    sandby.addEdge(&flyinge,4);
    hallestad.addEdge(&veberod,8);
    std::cout << "Anslutningar från " <<dalby.getName() << "(" << dalby.getValue() << ") :\n";
    for(auto de : dalby.getEdges()){
        std::cout << de.getLength() << " to " << de.getDestination()->getName() << std::endl;
    }
}