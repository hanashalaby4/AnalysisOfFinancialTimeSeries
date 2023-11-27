#ifndef _MAX_HEAP_
#define _MAX_HEAP_

#include "HeapClass.h"

class maxHeap : public heapClass {

protected:
    void heapifyUp(int i) override;
    void heapifyDown(int i) override;

public:
    maxHeap(int cap);
    Node extractMax();
};

#endif // _MAX_HEAP_
