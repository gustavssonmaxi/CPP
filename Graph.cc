#include <algorithm>
#include <memory>
#include <limits>
#include "Graph.h"
#include <fstream>
#include <sstream>


Graph::Graph(const std::string& filename) {
    std::ifstream file(filename); // Öppna filen

    if (!file) {
    throw std::runtime_error("\nKunde inte öppna filen: " + filename);
    }

}

void Graph::addNode(const std::string& node) {
    if (find(node) == nullptr) {
        
        // MAKE_UNIQUE FINNS INTE I C++11
        // nodeVector.push_back(std::unique_ptr<Node>(new Node(node))); 
        // ÄR ETT ALTERNATIV

        nodeVector.push_back(std::make_unique<Node>(node)); // Using make_unique instead of new
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