#ifndef _HEAP_CLASS_
#define _HEAP_CLASS_

#include "Node.h"
#include <vector>
#include <string>

class heapClass { 
protected:
    std::vector<Node> nodes; 
    int capacity; 

    void buildHeap();

    virtual void heapifyUp(int index) = 0;
    virtual void heapifyDown(int index) = 0;

public:
    heapClass(int cap);
    void insertKey(Node node);

    int parent(int i);
    int left(int i);
    int right(int i);
    const std::vector<Node>& getNodes() const;
    int getCapacity();
};

#endif //!_HEAP_CLASS_
