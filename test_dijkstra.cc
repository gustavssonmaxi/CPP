#include <iostream>
#include <cassert>
#include "dijkstra.h"
#include "Node.h"

using std::cout;
using std::endl;

/** Test för att se om Dijkstras algoritm fungerar.
Skapar noder och tillghörande edges och utför en
Dijkstraberäkning för att uppdatera nodernas värden.
Kollar sedan med assert om de blev som förväntat.
*/
void test()
{
    Node lund{"Lund"};
    Node dalby{"Dalby"};
    Node sandby{"Sodra Sandby"};
    Node hallestad{"Torna Hallestad"};
    Node flyinge{"Flyinge"};
    Node veberod{"Veberod"};

    lund.addEdge(&dalby, 12);
    lund.addEdge(&sandby, 12);
    dalby.addEdge(&sandby, 12);
    dalby.addEdge(&veberod, 11);
    dalby.addEdge(&hallestad, 5);
    sandby.addEdge(&lund, 12);
    sandby.addEdge(&flyinge, 4);
    hallestad.addEdge(&veberod, 8);

    dijkstra(&lund);

    assert(lund.getValue() == 0);
    assert(dalby.getValue() == 12);
    assert(sandby.getValue() == 12);
    assert(hallestad.getValue() == 17);
    assert(veberod.getValue() == 23);
    assert(flyinge.getValue() == 16);

/** Skriver ut värdena om ifdef ändras till ifndef för felsökning */
#ifdef INFO
    cout << "----\nAll distances from Lund:\n";

    for (auto &t : {lund, dalby, sandby, hallestad, veberod, flyinge})
    {
        cout << t.getName() << " : " << t.getValue() << " ";
        cout << endl;
    }
#endif
    cout << "test_dijkstra passed" << endl;
}

int main()
{
    test();
    return 0;
}
