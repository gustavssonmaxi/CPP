#ifndef GRAPH_H
#define GRAPH_H
#include "Node.h"
#include <memory>
#include <vector>
#include <string>

class Graph
{

public:
    Graph();

    Graph(std::istream &in);
    // Lägger till noden i nodeVector
    void addNode(const std::string &addNodeName);

    // Hittar en nod med namnet s och retunerar noden
    Node *find(const std::string &searchNodeName);

    // Återställer nodernas värden så att de kan återanvändas i en ny Dijkstra algoritm
    void resetVals();

    // Iterator för första noden i nodeVector
    std::vector<std::unique_ptr<Node>>::iterator begin() { return nodeVector.begin(); };

    // Iterator för sista noden i nodeVector
    std::vector<std::unique_ptr<Node>>::iterator end() { return nodeVector.end(); };

private:
    // Vektorn med noder som finns i ett Grapobjekt.
    std::vector<std::unique_ptr<Node>> nodeVector;
};

#endif