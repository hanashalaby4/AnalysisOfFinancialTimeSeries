#include "HeapClass.h"
#include <iostream>

heapClass::heapClass(int cap) {
    capacity = cap;
}

int heapClass::getCapacity() {
    return capacity;
}

const std::vector<Node>& heapClass::getNodes() const {
    return nodes;
}

int heapClass::parent(int i) {
    return (i - 1) / 2;
}

int heapClass::left(int i) {
    return 2 * i + 1;
}

int heapClass::right(int i) {
    return 2 * i + 2;
}

void heapClass::buildHeap() {
    for (int i = nodes.size() / 2 - 1; i >= 0; --i) {
        heapifyDown(i);
    }
}

void heapClass::insertKey(Node node) {
    if (nodes.size() == capacity - 1) {
        std::cout << "Heap full, could not insert\n";
        return;
    }

    nodes.emplace_back(node);
    heapifyUp(nodes.size() - 1);
}
