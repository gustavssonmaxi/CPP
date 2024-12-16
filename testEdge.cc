#include "Edge.h"
#include "Node.h"
#include <iostream>

int main(){
    Node N("Lund");
    Edge E(&N, 5);
    std::cout << "Stad: "<< E.getDestination()->getName() << ", Avstånd: "<<E.getLength() << std::endl;
}