#include "MaxHeap.h"

#include <iostream>
#include <stdexcept>

maxHeap::maxHeap(int cap) : heapClass(cap) {
    capacity = cap;
}

Node maxHeap::extractMax() {
    if (nodes.empty()) {
        throw std::runtime_error("The heap is empty");
    }

    Node maxNode = nodes.front();
    std::swap(nodes.front(), nodes.back());
    nodes.pop_back();
    heapifyDown(0);

    return maxNode;
}

void maxHeap::heapifyUp(int i) {
    while (i > 0) {
        if (nodes[i].rateChange > nodes[parent(i)].rateChange) {
            std::swap(nodes[i], nodes[parent(i)]);
            i = parent(i);
        }
        else {
            break;
        }
    }
}

void maxHeap::heapifyDown(int index) {
    int leftChild, rightChild, largestChild;

    while (true) {
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        largestChild = index;

        if (leftChild < nodes.size() && nodes[leftChild].rateChange > nodes[largestChild].rateChange) {
            largestChild = leftChild;
        }

        if (rightChild < nodes.size() && nodes[rightChild].rateChange > nodes[largestChild].rateChange) {
            largestChild = rightChild;
        }

        if (largestChild != index) {
            std::swap(nodes[index], nodes[largestChild]);
            index = largestChild;
        }
        else {
            break;
        }
    }
}
