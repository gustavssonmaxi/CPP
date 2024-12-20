// #include <algorithm>
#include "NodeSet.h"
#include "Node.h"

/** Skapar en tom mängd av noder. */
NodeSet::NodeSet()
{
    nodeVector = {};
}

/** Lägger till noden node till mängden,
om mängden inte redan innehåller en nod med samma namn. */
void NodeSet::add(Node *node)
{
    auto it = std::find_if(nodeVector.begin(), nodeVector.end(),
                           [node](Node *existingNode)
                           { return existingNode->getName() == node->getName(); });

    if (it == nodeVector.end())
    {
        nodeVector.push_back(node);
    }
}

/** Returnerar true om mängden noder är tom. */
bool NodeSet::isEmpty()
{
    return nodeVector.empty();
}

/** Väljer ut den nod som har lägst värde och returnerar den.
Den returnerade noden tas bort ur mängden.
Om mängden är tom returneras null. */
Node *NodeSet::removeMin()
{
    if (nodeVector.empty())
    {
        return nullptr;
    }
    std::sort(nodeVector.begin(), nodeVector.end(),
              [](Node *a, Node *b)
              { return a->getValue() < b->getValue(); });

    Node *minNode = nodeVector.front();
    nodeVector.erase(nodeVector.begin());

    return minNode;
}