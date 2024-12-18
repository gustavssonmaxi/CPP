#include <algorithm>
#include <memory>
#include <limits>
#include "Graph.h"
// #include <fstream>
#include <sstream>


Graph::Graph(){

}

Graph::Graph(std::istream& in) {
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream lineStream(line);
        std::string startNode, endNode;
        int distance;

        if (std::getline(lineStream, startNode, ':') && 
            lineStream >> distance && 
            std::getline(lineStream, endNode)) {

            // Trimma whitespace
            startNode.erase(0, startNode.find_first_not_of(" \t"));
            startNode.erase(startNode.find_last_not_of(" \t") + 1);
            endNode.erase(0, endNode.find_first_not_of(" \t"));
            endNode.erase(endNode.find_last_not_of(" \t") + 1);

            // Lägg till noder och bågen
            addNode(startNode);
            addNode(endNode);

            Node* start = find(startNode);
            Node* end = find(endNode);

            if (start && end) {
                start->addEdge(end, distance);
            } else {
                throw std::runtime_error("Kunde inte lägga till båge mellan " + startNode + " och " + endNode);
            }
        } else {
            throw std::invalid_argument("Felaktigt format i indata: " + line);
        }
    }
}


void Graph::addNode(const std::string& node) {
    if (find(node) == nullptr) {
        
        nodeVector.push_back(std::unique_ptr<Node>(new Node(node))); 
        // nodeVector.push_back(std::make_unique<Node>(node)); // Using make_unique instead of new
    }
}

Node* Graph::find(const std::string &node) {
    auto it = std::find_if(nodeVector.begin(), nodeVector.end(),
                            [&node](const std::unique_ptr<Node>& existingNode) {
                                return existingNode->getName() == node;
                            });

    if (it != nodeVector.end()) {
        return it->get(); // Return the raw pointer
    } else {
        return nullptr;
    }
}

void Graph::resetVals() {
    for (auto& node : nodeVector) {
        node->setValue(std::numeric_limits<int>::max());
    }
}