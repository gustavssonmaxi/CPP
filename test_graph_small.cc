#include <iostream>
#include <cassert>
#include "Graph.h"
#include <algorithm>
#include <utility>
#include <set>
#include <limits>

using std::cout;
using std::endl;

/** Test för att se om node och edges meldemsfunktioner
 * fungerar som förväntat m.h.a. assert.
 */
void test_node_and_edge()
{
    Node n("Test");
    assert(n.getName() == "Test");
    assert(n.getEdges().size() == 0);
    assert(n.getValue() == std::numeric_limits<int>::max());

    Node m("Test2");
    assert(m.getName() == "Test2");
    assert(m.getEdges().size() == 0);
    assert(m.getValue() == std::numeric_limits<int>::max());

    n.addEdge(&m, 17);
    assert(n.getEdges().size() == 1);
    assert(m.getEdges().size() == 0);

    auto& p = *n.getEdges().begin();
    assert(p.getDestination()->getName() == "Test2");
    assert(p.getLength() == 17);

    p.getDestination()->setValue(42);
    assert(n.getValue() == std::numeric_limits<int>::max());
    assert(m.getValue() == 42);

    cout << "test_node_and_edge passed" << endl;
}

void print_neighbours(Node* n)
{
    cout << "Anslutningar från " << n->getName() << "(" << n->getValue() << ") :\n";
    for(auto de : n->getEdges()){
        cout << de.getLength() << " to " << de.getDestination()->getName() << endl;
    }
}

/** Test för att se om Edges meldemsfunktioner
 * fungerar som förväntat m.h.a. assert.
 */
void test_edges()
{
    Node n_lund{"Lund"};
    Node n_dalby{"Dalby"};
    Node n_sandby{"Sodra Sandby"};
    Node n_hallestad{"Torna Hallestad"};
    Node n_flyinge{"Flyinge"};
    Node n_veberod{"Veberod"};

     n_lund.addEdge(&n_dalby,12);
     n_lund.addEdge(&n_sandby,12);
     n_dalby.addEdge(&n_veberod,11);
     n_dalby.addEdge(&n_hallestad,5);
     n_sandby.addEdge(&n_lund,12);
     n_sandby.addEdge(&n_flyinge,4);
     n_hallestad.addEdge(&n_veberod,8);

#ifdef INFO
    print_neighbours(&n_dalby);
#endif
    
    std::set<std::pair<std::string,int>> neighbours{{"Veberod",11},{"Torna Hallestad",5}};
    for(auto de : n_dalby.getEdges()){
        auto res = std::find_if(neighbours.begin(), neighbours.end(),
                [&](const std::pair<std::string,int> &x){return de.getDestination()->getName() == x.first;});
        assert(res != neighbours.end());
#ifdef INFO
        cout << "found " << res->first << endl;
#endif
        assert(res->second == de.getLength());
    }
    cout << "test_edges passed" << endl;
}


int main()
{
    test_node_and_edge();
    test_edges();
    return 0;
}
