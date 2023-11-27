#include "MinHeap.h"

#include <iostream>
#include <stdexcept>

minHeap::minHeap(int cap) : heapClass(cap) {
    capacity = cap;
}

Node minHeap::extractMin() {
    if (nodes.empty()) {
        throw std::runtime_error("The heap is empty");
    }

    Node minNode = nodes.front();
    std::swap(nodes.front(), nodes.back());
    nodes.pop_back();
    heapifyDown(0);

    return minNode;
}

void minHeap::heapifyUp(int i) {
    while (i > 0) {
        if (nodes[i].rateChange < nodes[parent(i)].rateChange) {
            std::swap(nodes[i], nodes[parent(i)]);
            i = parent(i);
        }
        else {
            break;
        }
    }
}

void minHeap::heapifyDown(int index) {
    int leftChild, rightChild, smallestChild;

    while (true) {
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        smallestChild = index;

        if (leftChild < nodes.size() && nodes[leftChild].rateChange < nodes[smallestChild].rateChange) {
            smallestChild = leftChild;
        }

        if (rightChild < nodes.size() && nodes[rightChild].rateChange < nodes[smallestChild].rateChange) {
            smallestChild = rightChild;
        }

        if (smallestChild != index) {
            std::swap(nodes[index], nodes[smallestChild]);
            index = smallestChild;
        }
        else {
            break;
        }
    }
}
