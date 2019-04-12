#if !defined(MAXHEAP_H)
#define MAXHEAP_H

#include<vector>

class CMaxHeap
{
private:
    std::vector<int> maxHeap;
    int n;
public:
    CMaxHeap();
    ~CMaxHeap();

    void buildMaxHeap();
    void maxHeapify(int i);

    void add(int key);
    int deleteMax();
    int getMaxKey();
    int getHeight();
    int getParent(int i);
    int getRightChild(int i);
    int getLeftChild(int i);

    void print();
    void heapSort();

};

#endif //MAXHEAP_H