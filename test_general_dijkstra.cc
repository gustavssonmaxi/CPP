#include <iostream>
#include <cassert>
#include "dijkstra.h"
#include "Node.h"

using std::cout;
using std::endl;

/** Funktion för att räkna steg */
int countSteps(Node *node, Edge &)
{
    return node->getValue() + 1;
}

/** Test för att se om generalDijkstras algoritm fungerar.
Skapar noder och tillghörande edges och utför en
generalDijkstraberäkning med funktionen countStep
för att uppdatera nodernas värden. Värdena blir nu istället
antal hopp ifrån startnoden.
Kollar sedan med assert om de blev som förväntat.
*/
void test()
{
    Node astorp{"Astorp"};
    Node kvidinge{"Kvidinge"};
    Node klippan{"Klippan"};
    Node perstorp{"Perstorp"};

    astorp.addEdge(&kvidinge, 2);
    astorp.addEdge(&perstorp, 8);
    kvidinge.addEdge(&astorp, 2);
    kvidinge.addEdge(&klippan, 2);
    klippan.addEdge(&kvidinge, 2);
    klippan.addEdge(&perstorp, 2);
    perstorp.addEdge(&klippan, 2);
    perstorp.addEdge(&astorp, 8);

    generalDijkstra(&astorp, countSteps);

    assert(astorp.getValue() == 0);
    assert(kvidinge.getValue() == 1);
    assert(klippan.getValue() == 2);
    assert(perstorp.getValue() == 1);

/** Skriver ut värdena om ifdef ändras till ifndef för felsökning */
#ifdef INFO
    cout << "----\nAll distances from Lund:\n";

    for (auto &t : {astorp, kvidinge, klippan, perstorp})
    {
        cout << t.getName() << " : " << t.getValue() << " ";
        cout << endl;
    }
#endif
    cout << "test_general_dijkstra passed" << endl;
}

int main()
{
    test();
    return 0;
}
