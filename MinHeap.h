#ifndef _MIN_HEAP_
#define _MIN_HEAP_
#include "HeapClass.h"

class minHeap : public heapClass {

protected:
    void heapifyUp(int i) override;
    void heapifyDown(int i) override;

public:
    minHeap(int cap);
    Node extractMin();
};

#endif //!_MIN_HEAP_
