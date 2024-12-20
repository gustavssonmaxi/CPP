#include <algorithm>
#include <memory>
#include <limits>
#include <iostream>
#include <sstream>
#include "Graph.h"

/** Konstruktorn för Graph som skapar ett Graphobjekt. */
Graph::Graph()
{
}

/** Konstruktorn för Graph om input är en istream från en fil.
Skapar en Graph som innehåller noderna med sina bågar och deras värden
om filen har formatet: Nodnamn: Båglängd destinationsNod. Som ex. Lund: 12 Dalby
*/
Graph::Graph(std::istream &in)
{
    std::string line;
    while (std::getline(in, line))
    {
        std::istringstream lineStream(line);
        std::string startNode, endNode;
        int distance;

        if (std::getline(lineStream, startNode, ':') &&
            lineStream >> distance &&
            std::getline(lineStream, endNode))
        {

            startNode.erase(0, startNode.find_first_not_of(" \t"));
            startNode.erase(startNode.find_last_not_of(" \t") + 1);
            endNode.erase(0, endNode.find_first_not_of(" \t"));
            endNode.erase(endNode.find_last_not_of(" \t") + 1);

            addNode(startNode);
            addNode(endNode);

            Node *start = find(startNode);
            Node *end = find(endNode);

            if (start && end)
            {
                start->addEdge(end, distance);
            }
            else
            {
                throw std::runtime_error("Kunde inte lägga till båge mellan " + startNode + " och " + endNode);
            }
        }
        else
        {
            throw std::invalid_argument("Felaktigt format i indata: " + line);
        }
    }
}

/** Lägger till noder till Graphobjektet. */
void Graph::addNode(const std::string &node)
{
    if (find(node) == nullptr)
    {
        nodeVector.push_back(std::unique_ptr<Node>(new Node(node)));
    }
}

/** Söker efter en Node i en Graph och retunerar denna om den finns. */
Node *Graph::find(const std::string &node)
{
    auto it = std::find_if(nodeVector.begin(), nodeVector.end(),
                           [&node](const std::unique_ptr<Node> &existingNode)
                           {
                               return existingNode->getName() == node;
                           });

    if (it != nodeVector.end())
    {
        return it->get(); // Return the raw pointer
    }
    else
    {
        return nullptr;
    }
}

/** Återställer nodernas värden i en Graph till maxvärdet för int. */
void Graph::resetVals()
{
    for (auto &node : nodeVector)
    {
        node->setValue(std::numeric_limits<int>::max());
    }
}