#include "Node.h"

std::vector<Node> createNodes(const Data& data, double average) {
    std::vector<Node> nodes;
    for (size_t i = 0; i < data.size(); ++i) {
        const auto& entry = data[i];
        nodes.push_back({ entry.first, entry.second - average });
    }
    return nodes;
}
