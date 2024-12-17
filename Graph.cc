#include "Graph.h"
#include <algorithm>
#include <memory>
#include <limits>

Graph::Graph() {
    
}

void Graph::addNode(const std::string& node) {
    if (find(node) == nullptr) {
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