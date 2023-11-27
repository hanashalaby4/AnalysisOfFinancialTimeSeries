#ifndef _NODE_
#define _NODE_
#include <string>
#include <vector>

typedef std::vector<std::pair<std::string, double>> Data;

struct Node {
    std::string date;
    double rateChange;
};

std::vector<Node> createNodes(const Data& data, double average);

#endif // !_NODE_
